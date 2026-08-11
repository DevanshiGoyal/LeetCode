//Approach-2 (Using Difference Array Technique)
//T.C : O(n)
//S.C : O(1001) ~= O(1)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001] = {0};

        for(auto &trip : trips) {
            int count = trip[0];
            int start = trip[1];
            int end   = trip[2];

            diff[start] += count;
            diff[end]   -= count;
        }

        int cumSum = 0;

        for(int i = 0; i < 1001; i++) {
            cumSum += diff[i];

            if(cumSum > capacity)
                return false;
        }

        return true;
    }
};