class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st ;

        for(int i = 2*n-1 ; i>=0 ; i--){
            int j = i%n;
            while(!st.empty() && nums[j] >= st.top()) st.pop();
            int temp = nums[j];
            if(i<n){
                if(st.empty()){
                    nums[j] = -1 ;
                }else{
                    nums[j] = st.top();
                }
            }
            st.push(temp);
        }
        return nums;
        
    }
};


