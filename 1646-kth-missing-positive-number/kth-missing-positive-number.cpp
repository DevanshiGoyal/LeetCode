class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int low = 1;
        int high = arr.size() + k;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int count = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();

            int missing = mid - count;

            if(missing < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};