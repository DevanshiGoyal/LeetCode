//Approach-1 (Using Line Sweep)
//T.C : O(n)
//S.C : O(n) to store events in map
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> events;

        for(auto &trip : trips) {
            int count = trip[0];
            int start = trip[1];
            int end   = trip[2];

            events[start] += count;
            events[end] -= count;
        }

        int passCount = 0;

        for(auto &it : events) {
            passCount += it.second;

            if(passCount > capacity)
                return false;
        }

        return true;
    }
};