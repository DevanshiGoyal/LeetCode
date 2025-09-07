class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int oddCount = 0;   // count of odds in current window
        int count = 0;      // total number of nice subarrays
        int prevCount = 0;  // number of valid left shifts (starting positions)
        int i = 0, j = 0;   // two pointers (window boundaries)

        while (j < n) {
            // If nums[j] is odd, increase odd count and reset prevCount
            if (nums[j] % 2 != 0) { 
                oddCount++;
                prevCount = 0; 
            }

            // If window has exactly k odds
            while (oddCount == k) {
                prevCount++; // each left shift gives a new valid subarray
                if (nums[i] % 2 != 0) oddCount--; // reduce odd count if removing odd
                i++; // shrink window from left
            }

            // Add all valid subarrays ending at j
            count += prevCount; 
            j++;
        }

        return count;
    }
};