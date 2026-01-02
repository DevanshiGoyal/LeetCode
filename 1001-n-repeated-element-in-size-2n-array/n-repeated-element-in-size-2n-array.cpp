// Intution
//Since the array has size 2N and exactly one element is repeated N times, the moment we see an element for the second time, we already have our ans
//So instead of counting everything, we can stop early as soon as repetition is detected
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        int n = nums.size();

        unordered_map<int, int> mpp;

        for(int i=0;i<n;i++)
        {
            if(mpp[nums[i]] == 0) mpp[nums[i]]++;
            else return nums[i];
        }

        return -1;
    }
};

//TC---> O(N)  SC--->O(N)