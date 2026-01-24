class Solution {
public:
    const int MOD = 1e9 + 7;

    // Function to find Next Smaller Element (NSE) for each index
    vector<int> findnse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            // Pop until we find a smaller element
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();

            // If no smaller element on right → use n
            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return nse;
    }

    // Function to find Previous Smaller or Equal Element (PSEE) for each index
    vector<int> findpsee(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // Pop until we find a smaller or equal element
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            // If none on left → use -1
            psee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        // Get next smaller and previous smaller/equal arrays
        vector<int> nse = findnse(arr);
        vector<int> psee = findpsee(arr);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];   // ways to extend left
            long long right = nse[i] - i;   // ways to extend right

            // Add contribution of arr[i]
            total = (total + (left * right % MOD) * arr[i]) % MOD;
        }

        return (int)total;
    }
};