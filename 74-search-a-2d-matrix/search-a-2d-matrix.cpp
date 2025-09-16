class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int start = 0;
        int end = matrix.size() - 1;
        int n = matrix[0].size();
        while(start <= end){
            int mid = start + (end - start)/2;
            if(matrix[mid][n-1] == target){
                return true;
            }else if(matrix[mid][n-1] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        if(start == matrix.size()){
            return false;
        }
        int s = 0;
        int e = n-1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(matrix[start][m] == target){
                return true;
            }else if(matrix[start][m] < target){
                s = m + 1;
            }else{
                e = m - 1;
            }
        }
        return false;
        
    }
};