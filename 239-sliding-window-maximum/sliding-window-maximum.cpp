class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> maxies;
        vector<int> res(n - k + 1);
        int idx = 0;
        int i = 0;
        int j = 0;

        while (j < n) {
            
            // from right remove elements smaller than current element
            while (!maxies.empty() && maxies.back() < nums[j]) {
                maxies.pop_back();
            }

            // now push current element
            maxies.push_back(nums[j]);

            // if it hits window size
            if (j - i + 1 == k) {
                res[idx++] = maxies.front();
                // window is going to move => element at the start of window useless => if its in deque => remove it
                if (maxies.front() == nums[i]) {
                    maxies.pop_front();
                }
                i++;
            }
            j++;
        }

        return res;
    }
};