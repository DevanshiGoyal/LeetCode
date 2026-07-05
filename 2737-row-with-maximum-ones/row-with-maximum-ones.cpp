class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m =  mat[0].size();
        
        int max1 = 0 ;
        int row = 0 ;

        for(int i = 0 ; i<n ; i++){
            
            int cnt1 = 0 ;
            for(int j = 0 ; j<m ; j++){
                if(mat[i][j] == 1) cnt1++;
                
            }
            if(cnt1>max1){
                row = i ;
                max1 = cnt1;

            }

        }

        return {row , max1} ;
        
    }
};
////o(m*n)