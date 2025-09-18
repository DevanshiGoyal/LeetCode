class Solution {
public:
    int maxElement(vector<int>& piles){
        int maxi = INT_MAX ;
        for(int i = 0 ; i<piles.size() ; i++){
            if(piles[i] > maxi){
                maxi = max(maxi , piles[i]) ;
            }
        }
        return maxi ;
    }
    int calculateTotalHours(vector<int>& piles, int hourly){
        int totalhrs = 0 ;
        for(int i = 0 ; i<piles.size() ; i++){
            totalhrs+= ceil(double(piles[i]) / double(hourly));

        }
        return totalhrs;

    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1 , high = maxElement(piles) ;
        while(low <= high){
            int mid = low + (high - low)/2 ;
            int totalhrs = calculateTotalHours(piles , mid);
            if(totalhrs <= h){
                high = mid-1 ;
            }else{
                low = mid+1 ;
            }
        }
        return low ;
        
    }
};

// TC---> O(N) * log(maxi)
// sc---> o(1)