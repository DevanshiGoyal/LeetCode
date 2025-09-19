class Solution {
public:
    int maxweight(vector<int>& weights){
        int sum =0;
        for(int i = 0 ; i<weights.size() ; i++){
            sum += weights[i];
        }
        return sum ;
    }
    int findDays(vector<int>& weights, int cap){
        int load = 0 ;
        int day = 1 ;
        for(int i = 0 ; i<weights.size() ; i++){
            if(weights[i]+load > cap)
            {
                day += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return day ;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end());
        int e = maxweight(weights);
        while(s<=e){
            int mid = (s+e)/2;
            if(findDays(weights , mid)<=days){
                e = mid-1 ;
            }else{
                s = mid+1 ;
            }

        }
        return s;
        
    }
};
//tc-->O(n⋅log(sum(weights)))