class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<double>left,right;
        vector<double>res;

        int i=0,j=0;

        while(j<n){

            if(left.empty() || left.size()<=right.size()){
                left.insert(nums[j]);
            }else{
                right.insert(nums[j]);
            }

            if(!right.empty() && *left.rbegin()>*right.begin()){
                double temp1=*left.rbegin();
                double temp2=*right.begin();
                left.erase(left.find(temp1));
                right.erase(right.find(temp2));

                right.insert(temp1);
                left.insert(temp2);
            }
            if(j-i+1==k){
                if(left.size()==right.size()){
                    double x = *left.rbegin() + *right.begin();
                    res.push_back((double)x/(2*1.0));
                }else
                    res.push_back((double)*left.rbegin());

                if(left.find(nums[i])!=left.end()){
                    left.erase(left.find(nums[i]));
                }else{
                    right.erase(right.find(nums[i]));
                }
                i++;
            }

            j++;
        }
        return res;
    }
};