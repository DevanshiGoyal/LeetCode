class Solution {
public:
    //sliding window technique 
    int totalFruit(vector<int>& fruits) {

        int l = 0 , r = 0 , maxlen = 0 ;
        int n = fruits.size();

        // hash map to store the count of each type fruit ;
        unordered_map<int , int> basket ;

        while(r<n){
            basket[fruits[r]]++;

            //If the map has more than 2 fruit types
            //shrink the window from start until back to only two types
            if(basket.size()>2){
                basket[fruits[l]]--;

                if(basket[fruits[l]]==0){
                    basket.erase(fruits[l]);

                }
                l++;
            }
            
            maxlen = max(maxlen , r-l+1);
            r++;
        } 

        return maxlen ;
        
    }
};

// TC--->O(N)
// SC--->O(1) 
//The map stores at most 3 keys at any point (though 2 is the limit, temporarily it might hold 3 during adjustment).