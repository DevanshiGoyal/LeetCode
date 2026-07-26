class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        vector<int> ans(2);
        int maxi = INT_MIN ;

        for(int i = 0 ; i<mat.size() ; i++){
            for(int j = 0 ; j<mat[0].size() ; j++){
                if(mat[i][j] > maxi){
                    maxi =  mat[i][j] ;
                    ans[0] = i ;
                    ans[1] = j ;
                }
            }
        }

        return ans ;
    }
};