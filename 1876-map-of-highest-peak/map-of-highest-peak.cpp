class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> height(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));

        vector<int> delrow = {0,0,-1,1};
        vector<int> delcol = {-1,+1,0,0};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                } 
            }
        } 


        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int h = q.front().second;
            height[x][y] = h;
            q.pop();
            for(int i=0;i<4;i++){
                int r = x + delrow[i];
                int c = y + delcol[i];
                if(r>=0 && r<n && c>=0 && c<m && vis[r][c]!=1){
                    q.push({{r,c},h+1});
                    vis[r][c] = 1;
                }
            }
        }
        return height;
    }

};