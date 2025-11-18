class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        const int n=bits.size();
        int i=0;
        for(; i<n-1; i++){ // Proceed the loop from i=0 to n-2
            if(bits[i]==1) i++; // the valid segment "10" or "11"
        }
        return i==n-1; // if the last  valid segment is "10" or "11" i==n otherwise i==n-1
    }
};