class Solution {
public:
    int bouquets(vector<int>& bloomDay, int mid, int k){
        //number of bouquets that can be made on that day 
        //by counting the consecutive bloomed flowers

        int count =  0 ;
        int bouquets = 0 ;

        for(int i = 0 ; i<bloomDay.size() ; i++){

           //if the flower is bloomed, add to the set--> else reset the count
            if(bloomDay[i] <= mid ){
                count ++ ;
            }
            else{
                count = 0 ;
                
            }
            if(count == k){
                bouquets++ ;
                count = 0 ;
            }
        
        }
        return bouquets ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();
        // edge case 
        if((long)m*k > n) return -1; // without long runtime error 
        int start = 0;
        int end = 0;

        // finding max day for range 
        for (int day : bloomDay) {
            end = max(end, day);
        }

        int mindays = -1 ;

        // binary search to find mindays 
        while(start <= end){
            int mid = (start +  end)/2 ;
            if(bouquets(bloomDay , mid , k) >=m){
                mindays = mid ;
                end = mid -1 ;
            }
            else{
                start = mid +1 ;
            }
        }
        return mindays ;
        
    }
};
// tc---> o( n log d) n--> no. of flowers , d --> highest value in bloomDay array 
//The search space is from 1 to d and for each of the chosen values of mid in the binary search we will iterate over the n flowers ---> the tc is equal to O(n log d)
// sc---> o(1)