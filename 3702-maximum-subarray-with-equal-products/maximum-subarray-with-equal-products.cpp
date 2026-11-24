class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        for(int i =0;i<nums.size();i++){
            int product = 1;
            int g=0;
            int l=1;
            for(int j=i;j<nums.size();j++){
                product*=nums[j];
                g=gcd(g,nums[j]);
                l=lcm(l,nums[j]);
                if(product==g*l) ans = max(ans,j-i+1);
                if(product>g*l) break;
            }
        }
        return ans;
    }
};