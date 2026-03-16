class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        
        for (int num : nums) {
            mp[num]++;
        }
        
        
        vector<int> result;
        for (auto el : mp) {
            if (el.second == 1) {
                result.push_back(el.first);
            }
        }
        
        return result;
        
    }
};