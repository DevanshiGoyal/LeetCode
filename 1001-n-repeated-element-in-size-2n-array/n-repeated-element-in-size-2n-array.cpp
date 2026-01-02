class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int ,  int> count;

        for(int i = 0 ; i<nums.size() ; i++ ){
            count[nums[i]]++;
        }

        int ans = -1;
        for(auto pair: count){
            int a = pair.first;
            int b = pair.second;
            if(b >= n/2){
                ans = a;
            }
        }

        return ans;
        
    }
};