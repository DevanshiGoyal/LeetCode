class Solution {
public:

    
    int findGCD(int a, int b) {

        if (b == 0) {
            return a;
        }
        
        return findGCD(b, a % b);
    }

    int findLCM(int a, int b) {

        return a * b / findGCD(a, b);
    }

    int maxLength(vector<int>& nums) {
        

        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int gcd = nums[i];
            int lcm = nums[i];
            long long product = nums[i];

            for (int j = i+1; j < n; j++) {

                gcd = findGCD(gcd, nums[j]);
                lcm = findLCM(lcm, nums[j]);
                product *= nums[j];

                if (product > lcm * gcd) break;
                
                if (product == lcm * gcd) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};