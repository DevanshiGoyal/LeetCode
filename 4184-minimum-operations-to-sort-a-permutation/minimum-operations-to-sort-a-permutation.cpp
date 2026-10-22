class Solution {
public:
    int minOperations(vector<int>& nums) {
        int zero{}, n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) zero = i;
        }

        int leftPrev{nums[zero]}, rightPrev{nums[zero]};
        bool leftValid = true, rightValid = true;

        for(int i = 1; i < n; i++){
            int left = (zero - i + n) % n;
            int right = (zero + i) % n;

            if(nums[right] < rightPrev)
                rightValid = false;

            if(nums[left] < leftPrev)
                leftValid = false;

            leftPrev = nums[left];
            rightPrev = nums[right];
        }

        int ans = INT_MAX;

        if(rightValid){
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        if(leftValid){
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};