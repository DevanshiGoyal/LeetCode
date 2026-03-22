class Solution {
public:
    static bool comp(vector<int>&a , vector<int>& b){
        return(a[1]>b[1]) ;
    }
    // Fractional knapsack 
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n =  boxTypes.size() ;
        // Sort Array according to the 2nd element using Comparator function
        sort(boxTypes.begin() ,boxTypes.end() , comp);

        int ans = 0;
        //greedily pick boxes till capacity is full
        for(auto box : boxTypes){
            int x = min(box[0] , truckSize) ;
            ans+=(x*box[1]) ; // adding units
            truckSize-=x;  //reduce the capacity
            if(!truckSize) break ; // full
        }

        return ans ;
        
    }
};
