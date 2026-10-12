class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        /** if you observe , the question is just to transfer the set bit from one number to
        another number.
        check , at the end of all the transfers i.e the OR and AND operations , the total count of set bits across all elements in fact even if we check at a particular set bit location across all numbers remains same , its just a simple transfer;
        */
        /**
        My approach is very simple :
        1) count number of set bit at each bit position at all location
        2) then k numbers using the number of bits
        3) we construct the numbers greedily
        */
        long long MOD=1e9+7;
        vector<int> bits(31,0); 
        // this array is to store the count of set bits at i bit position across all the numbers

        for(int e:nums)
        {
            for(int i=0;i<31;i++)
            {
                if(e & (1<<i)) // check if bit is set
                bits[i]++; // increase the count if bit set at ith position
            }
        }
        long long ans=0;
        while(k--) // since we have to construct k number
        {
            long long x=0; // generate number
            for(int b=0;b<31;b++)
            {
                if(bits[b]>0) // if we can use bit at b'th position
                {
                    x|=1LL<<b;
                    bits[b]--; // since we used a bit , so reduce count
                }

            } 
            ans=(ans + x*x) % MOD;

        }
        return ans;

    }
};