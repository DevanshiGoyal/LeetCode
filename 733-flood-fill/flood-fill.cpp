class Solution {
public:

    void dfs(int r , int c , vector<vector<int>> &vis , vector<vector<int>>& image, int newColor , int currColor){
        int m = image.size() ;
        int n = image[0].size();
        

        if(r<0 || r>=m || c<0 || c>=n || vis[r][c] || image[r][c] != currColor) return ;

        image[r][c] = newColor;

        vis[r][c] = 1;

        int dr[] = {-1 , 0 , 1 , 0};
        int dc[] = {0 , 1 , 0 ,-1};

        for(int  i = 0 ; i<4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            dfs(nr,  nc , vis , image , newColor , currColor);
        }



    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size() ;
        int n = image[0].size();

        vector<vector<int>> vis(m , vector<int>(n , 0));

        dfs(sr , sc , vis , image, color,image[sr][sc] );
        return image ;
        
    }
};