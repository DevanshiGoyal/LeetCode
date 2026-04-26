class Solution {
public:
    
    vector<int> findValidElements(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> ans;
        
        // first element always valid
        ans.push_back(nums[0]);
        
        for(int i = 1; i < n - 1; i++) {
            
            bool greaterLeft = true;
            bool greaterRight = true;
            
            // check left side
            for(int j = 0; j < i; j++) {
                
                if(nums[i] <= nums[j]) {
                    greaterLeft = false;
                    break;
                }
            }
            
            // check right side
            for(int j = i + 1; j < n; j++) {
                
                if(nums[i] <= nums[j]) {
                    greaterRight = false;
                    break;
                }
            }
            
            // valid if any one condition true
            if(greaterLeft || greaterRight) {
                ans.push_back(nums[i]);
            }
        }
        
        // last element always valid
        if(n > 1)
            ans.push_back(nums[n - 1]);
        
        return ans;
    }
};