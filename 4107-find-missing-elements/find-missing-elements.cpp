class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end()); // min element
        int mx = *max_element(nums.begin(), nums.end()); // max element 
    
        unordered_set<int> present(nums.begin(), nums.end());
        vector<int> missing;
    
        for (int i = mn; i <= mx; i++) {
            if (present.find(i) == present.end()) {
                missing.push_back(i);
            }
        }
    
        return missing;
    }
};