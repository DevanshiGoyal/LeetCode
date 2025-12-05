class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        int i = 0;
        while (i + 1 < n) {

            int sumleft = 0; 
            int sumright = 0;

            // sum of left part [0...i]
            for (int k = 0; k <= i; k++) {
                sumleft += nums[k];
            }

            // sum of right part [i+1...n-1]
            for (int z = i + 1; z < n; z++) {
                sumright += nums[z];
            }

            // check condition
            if (abs(sumleft - sumright) % 2 == 0) {
                count++;
            }

            i++;  
        }

        return count;
    }
};
