class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int sum = 0;
        //first k elements in  window
        for(int i = 0 ; i<k ; i++){
            sum+=cardPoints[i];
        }

        int curr= sum ;
        //remove the last visited element and add the non-visited element from the last
        for(int i = k-1 ; i>=0 ; i--){
            curr-=cardPoints[i];
            curr+=cardPoints[n-k+i];
            //check the maximum value any possible combination can give
            sum = max(sum , curr);

            
        }
        
        return sum ;

       
    }
};
//TC-->O(N)
//SC--->O(1)