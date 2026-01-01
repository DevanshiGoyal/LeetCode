
class Solution {
public:
    // Function to find triplets with sum zero
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();

        // Sort the array
        sort(arr.begin(), arr.end());
        // Store final result
        vector<vector<int>> ans;

        // First loop for first element
        for (int i = 0; i < n; i++) {
            // Skip duplicates for first element
            if (i > 0 && arr[i] == arr[i - 1]) continue;

            // Two pointers
            int left = i + 1, right = n - 1;

            // Find pairs for current arr[i]
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == 0) {
                    ans.push_back({arr[i], arr[left], arr[right]});
                    left++, right--;

                    // Skip duplicates for left
                    while (left < right && arr[left] == arr[left - 1]) left++;
                    // Skip duplicates for right
                    while (left < right && arr[right] == arr[right + 1]) right--;
                }
                else if (sum < 0) left++;
                else right--;
            }
        }
        return ans;
    }
};

//TC--> O(N^2)   SC--->O(1)