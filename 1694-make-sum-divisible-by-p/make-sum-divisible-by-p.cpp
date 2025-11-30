class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        long totSum = 0;
        for (int x : nums) totSum += x;

        long target = totSum %p ;
        if(target == 0) return 0 ;

        unordered_map<int , int> mp ;
        mp[0] = -1 ;

        long prefix = 0  ;
        int n = nums.size();

        for(int i = 0 ; i<nums.size() ; i++){
            prefix = (prefix + nums[i]) % p ;
            int need = (prefix - target + p) % p;

            if (mp.count(need))
                n = min(n, i - mp[need]);

            mp[(int)prefix] = i;
        }

        return n == nums.size() ? -1 : n;        
        
    }
};