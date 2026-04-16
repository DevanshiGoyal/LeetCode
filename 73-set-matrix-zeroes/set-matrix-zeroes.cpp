//Using m+n extra space
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();        // number of rows
        int n = matrix[0].size();     // number of columns

        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = true; //mark it for zero
                    col[j] = true; //mark it for zero
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
