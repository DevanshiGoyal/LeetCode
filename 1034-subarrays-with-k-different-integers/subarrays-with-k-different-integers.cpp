class Solution {
public:
    int countAtmost(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0, r = 0;
        int ctr = 0;
        unordered_map<int,int> mpp;
        while (r<n){
            mpp[nums[r]]++;
            while (mpp.size()>k){
                mpp[nums[l]]--;
                if (mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            if (mpp.size()<=k){
                ctr+=(r-l+1);
            }
            r++;
        }
        return ctr;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int vg = countAtmost(nums,k);
        int vg1 = countAtmost(nums,k-1);
        return vg-vg1;
        
    }
};