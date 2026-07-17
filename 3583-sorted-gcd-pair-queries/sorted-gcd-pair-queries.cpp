class Solution {
public:
    

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        // OPTIMAL -> so the first thing is we dont actually have to find gcd of every pair ,we can just store the multiples of all numbers and then we'll perform certain operations on them to know exactly which elemnt will be on queries[i] index in our gcd array if it existed .
        // Intuition and how will i procee to solve it :- so sabse phle we have to make a count array , size will be *max_ele+1,as it is gonna store number of times an elements comes
        // after that i can we'll count how many of those numbers are multiple of d, d will start from 1 and till *max_ele then we'll get an array of multiplles
        // now we'll count how many pairs are there that are exact multiples of an index, for a value n ,total number of pairs possible=n*n-1, now here 1,2 and 2,1 will be counted as separate pairs but we have to count them as 1 single pair so we'll divide by 2 ,now for an index d ,total number of pairs = ((n*(n-1))/2) where n is the value at d ,that is total number of elements divisible by d ,now to know exact number of pairs divisible by d ,we'll minus it with number of pairs of every other multiple starting from 2,now we have an array containing exact number of pairs of elemets divisible by an index ,or u can say that the index will be their gcd ,now we'll make a prefix sum array containing number of elements divisible by 1---i ,for an index i,after that we just have to do binary sum on our prefix array to get the index where value is just greater than queries[i],that'll index will be our ans for that query as here our index is basically acting as gcd and the values as number of elemnts having gcd 1 ..to... our index 
        // now we implement 
        int maxi=*max_element(nums.begin(),nums.end());
        vector<long long>count(maxi+1);
        for(int i=0;i<nums.size();i++) count[nums[i]]++;
        vector<long long>count_div(maxi+1);
        for(int d=1;d<=maxi;d++)
        {
            for(int j=d;j<=maxi;j+=d)
            {
                count_div[d]+=count[j];
            }
        }
        vector<long long>exact(maxi+1);
        for(int d=maxi;d>=1;d--)
        {
            long long c=count_div[d];
            exact[d]=(c*(c-1))/2;
            for(int j=2*d;j<=maxi;j+=d)
            {
                exact[d]-=exact[j];
            }
        }
        vector<long long>prefix_arr(maxi+1);
        for(int i=1;i<=maxi;i++)
        {
            prefix_arr[i]=prefix_arr[i-1]+exact[i];
        }
        vector<int>ans;
        for(long long i=0;i<queries.size();i++)
        {
            int s=1;
            int e=maxi;
            long long query=queries[i];
            while(s<e)
            {
                int mid=s+(e-s)/2;
                if(prefix_arr[mid]>query) e=mid;
                else s=mid+1;
            }
            ans.push_back(s);
        }
        return ans;
    }
};