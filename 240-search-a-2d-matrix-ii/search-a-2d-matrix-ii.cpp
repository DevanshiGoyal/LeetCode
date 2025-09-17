class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Gets the no. of rows
        int row = matrix.size();

        // gets the no. of columns
        int col= matrix[0].size();

        // gets the index of element  to  be compared 
        // here it is last element of 1st row ----> 15
        int rowIndex = 0 ;
        int colIndex = col -1 ;

        
        while( rowIndex < row && colIndex >= 0){
            int element =matrix[rowIndex][colIndex];

            // Founds the target 
            if( element == target ){
                return 1;
            }
            // checks if it is less it will be in next row
            else if ( element < target ){

                rowIndex ++ ;

            }
            else{
            // if greater then columnIndex -- 
                colIndex-- ;
            }
        }
        return 0;
    }
};