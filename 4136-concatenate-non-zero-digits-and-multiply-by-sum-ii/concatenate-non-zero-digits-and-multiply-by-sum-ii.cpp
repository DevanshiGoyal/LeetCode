class Solution {
public:
    // brute force O(n*q)--> TLE
    /*
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> ans ;
        int mod = 1e9 + 7 ;
        for(auto &it : queries){
            int l = it[0] ;
            int r = it[1];
            long long x = 0 , sum = 0 ;
            for(int i = l ; i<=r ; i++){
                if(s[i] != '0' ){
                    int d = s[i] - '0' ;
                    sum+=d ;
                    x = (x*10 + d)%mod ;
                }
            }
            
            long long a = (x * sum) % mod;
            ans.push_back(a) ;
        }

        return ans ;
        */

        
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        /*
        Time: O(n + q log n)
        Space: O(n)
        */
        const int mod = 1e9 + 7;
        int n = s.size();

        vector<int> pos;
        vector<int> digit;

        // Store non-zero digits and their positions
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int k = digit.size();

        // powers of 10
        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % mod;

        // prefix concatenated number
        vector<long long> prefNum(k + 1, 0);
        for (int i = 0; i < k; i++)
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % mod;

        // prefix digit sum
        vector<long long> prefSum(k + 1, 0);
        for (int i = 0; i < k; i++)
            prefSum[i + 1] = prefSum[i] + digit[i];

        vector<int> ans;

        for (auto &q : queries) {

            int L = q[0];
            int R = q[1];

            int left = lower_bound(pos.begin(), pos.end(), L) - pos.begin();
            int right = upper_bound(pos.begin(), pos.end(), R) - pos.begin() - 1;

            if (left > right) {
                ans.push_back(0);
                continue;
            }

            int len = right - left + 1;

            long long x = (prefNum[right + 1]
                          - (prefNum[left] * pow10[len]) % mod
                          + mod) % mod;

            long long sum = prefSum[right + 1] - prefSum[left];

            ans.push_back((x * sum) % mod);
        }

        return ans;
    }
};