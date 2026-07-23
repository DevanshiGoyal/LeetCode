class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n=dungeon[0].size();
        //NOTE : We will write bottom up by traversing from bottom right to top left because 
        // when we find t[i][j] we must be already aware of the health for down (t[i+1][j) and right (t[i][j+1])
      
        vector<vector<int>> t(m, vector<int>(n, 0));
        //t[i][j] = min health needed to reach (m-1, n-1) from (i,j)

        // Fill the rest of the DP table
        for(int i=m-1;i>=0;--i){
            for(int j=n-1;j>=0;--j){
                if(i==m-1 && j==n-1){
                    t[i][j] = (dungeon[m-1][n-1] > 0 ? 1 : abs(dungeon[m-1][n-1]) + 1);
                } else{
                    int down  = (i+1 >= m) ? 1e9 : t[i+1][j];  // Health needed if moving down
                    int right = (j+1 >= n) ? 1e9 : t[i][j+1]; // Health needed if moving right
                    int res = min(down, right) - dungeon[i][j];  // Calculate the required health

                    // If the result is <= 0, we need at least 1 health
                    t[i][j] = (res > 0 ? res : 1);
                }
            }
        }

        // The result is the minimum health required to start at the top-left corner
        return t[0][0];
    }
};