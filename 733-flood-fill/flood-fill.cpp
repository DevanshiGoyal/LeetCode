class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        int initialC = image[sr][sc];
        if(initialC == color) return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        // Dir (up, right, down, left)
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                   && image[nrow][ncol] == initialC){
                    
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }

        return image;
    }
};