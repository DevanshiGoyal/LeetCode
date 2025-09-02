class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // n*n matrix
        int n = grid.size() ;
        
         // If the start or end cell is blocked --->'1, return -1
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1 ;


        //queue to store pair {distance , {row , col}}
        //not using PriorityQueue , because the changing factor i.e "distance" is being incremented uniformly (+1)
        //unlike when weights are not uniform we use PQ 
        //inorder to keep the node with least distance at top of the queue

        queue<pair<int , pair<int , int>>> q ;

        q.push({1 ,{0 , 0}}) ;

        // Distance matrix is not needed here bcz  directly marking cells  in the grid
        grid[0][0] = 1; // Mark as visited with distance

        // 8 directions 

        vector<int> dr = {-1 , -1 , 0 , +1 , +1 , +1 , 0 , -1} ;
        vector<int> dc = {0 , +1 , +1 , +1 , 0 , -1 , -1 , -1} ;
        
        //(E+V)log V
        while(!q.empty()){
            auto it = q.front() ;
            q.pop() ;

            int dist = it.first ;
            int r = it.second.first ;
            int c = it.second.second ;

            // destination reached ----> end cell (n-1 , n-1)
            if (r == n - 1 && c == n - 1) return dist;

            // checking all 8 possible neighbours 
            for(int i = 0 ; i<8 ; i++){
                int newr  = r + dr[i] ;
                int newc = c + dc[i] ;

                // moving and checking new cell and updating grid 
                if(newr>=0 && newr < n && newc>=0 && newc< n && grid[newr][newc] == 0 ){
                    grid[newr][newc] = 1; // Mark as visited
                    q.push({dist+1 , {newr , newc}}) ;

                }
            }
        }

        // if no path found 
        return -1 ;
        
    }
};

//TC--> O(n2) — In the worst case, we visit every cell once.
//Sc--->O(n) — For the BFS queue.
