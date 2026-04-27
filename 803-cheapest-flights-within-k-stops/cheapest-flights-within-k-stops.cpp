class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // create the graph 

        vector<vector<pair<int , int>>>adj(n) ;
        for(auto it : flights ){
            adj[it[0]].push_back({it[1] , it[2]}) ;

        }

        queue<pair<int , pair<int , int>>> q ;
        // {stops , { node , cost}}
        q.push({0 , {src , 0}}) ;
        vector<int> dist(n , 1e9) ;
        dist[src] = 0 ;
        // Dijikstra's algo 
        // Tc---> flights.size() -->// total no. of edges
        // not taking log V term as there is no priority Q 
        while(!q.empty()){
            auto it = q.front() ;
            q.pop() ;
            int stops = it.first ;
            int node = it.second.first ;
            int cost = it.second.second ;

        
            if(stops > k ) continue ;
            for(auto it : adj[node]){
                int adjNode = it.first ;
                int edW = it.second ;

                if(cost + edW < dist[adjNode] && stops<=k){
                    dist[adjNode] = cost + edW ;
                    q.push({stops+1 , {adjNode , dist[adjNode]}}) ;
                }

            }
        }



        if(dist[dst] == 1e9) return -1 ; // we didnt reached
        return dist[dst] ;

        
    }
};

// Time complexity:O(e∗k)
//Space complexity:O(V+E) for adjacency list + O(V) for distance array + O(V) for queue.

