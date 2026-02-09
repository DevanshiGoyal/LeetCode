class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxAverage = INT_MIN;
        int i = 0;
        int j = 0;
        int sum = 0;

        while(j < n){
            // Sum for current Window
            sum += nums[j];

            // if window Size is 'k' means get the average and slide the window
            if(j-i+1 == k){
                maxAverage = max(maxAverage, (double)sum/k);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return maxAverage;
    }
};