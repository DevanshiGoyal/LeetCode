class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // observation based approach ---> maths 
        //The intution is 
        // the adj elemnt can become +ve if even number of neg present in matrix then all element can become +ve 
        //but if odd number of neg present then min element is subtracted from the sum

        int minVal = INT_MAX ;
        long long sum = 0  ;
        int m = matrix.size();
        int n = matrix[0].size();
        int countn = 0 ; // counting negatives
        for(int i = 0 ; i< m ; i++) {
            for(int j = 0 ; j<n ; j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0){
                    countn++;    
                }
                
                minVal = min(minVal, abs(matrix[i][j])); 
            }
        }
        if(countn%2==0)return sum;
        return sum-2*minVal;
        
    }
};

//TC-->O(n^2)  SC--->O(1)