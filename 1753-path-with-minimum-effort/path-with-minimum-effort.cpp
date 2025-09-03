class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n =  heights.size() ;
        int m = heights[0].size() ;

        // min heap
        // {dis , {row, col}}
        priority_queue<pair<int ,pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq ;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0 ,{0 , 0}}) ;

        // Dijikstra's algorithm 
        while(!pq.empty()){
            auto it = pq.top() ;
            pq.pop() ;

            int dis = it.first ;
            int row = it.second.first ;
            int col = it.second.second ;

            // 4 possible directions 
            // neighbours 
            vector<int> dr = {-1 , 0 , +1 , 0} ;
            vector<int> dc = {0 , -1 , 0 , +1} ;

        

            // Stop if we've reached the bottom-right cell
            if (row == n - 1 && col == m - 1)
                return dis;

            for(int i = 0 ; i<4 ; i++){
                int nrow = row + dr[i] ;
                int ncol = col + dc[i] ;

                if(nrow<0 || nrow>=n || ncol<0 || ncol>=m) continue ;
                int ndist = max(abs(heights[row][col] - heights[nrow][ncol]),dis);

                if(ndist < dist[nrow][ncol]){
                    dist[nrow][ncol] = ndist ;
                    pq.push({ndist , {nrow , ncol}}) ;
                }
            }


        }

        return 0 ;
        
    }
};