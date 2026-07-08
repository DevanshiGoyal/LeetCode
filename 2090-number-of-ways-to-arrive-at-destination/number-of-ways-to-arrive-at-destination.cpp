class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        // adj list 
        vector<vector<pair<long long , int>>> adj(n) ;

        for(auto edge : roads){
            adj[edge[0]].push_back({edge[1] , edge[2]});
            adj[edge[1]].push_back({edge[0] , edge[2]});

        }

        priority_queue<pair<long long , int> , vector<pair<long long, int>> , greater<pair<long long , int>>> pq ;

        vector<long long> dist(n , LONG_MAX) ;

        vector<int> ways(n , 0) ;

        dist[0] = 0 ;
        ways[0] = 1;
        pq.push({0 , 0});  // time , node

        int mod = (int)(1e9 + 7) ;

        while(!pq.empty()){
            long long dis = pq.top().first ;
            int node =  pq.top().second ;
            pq.pop() ;

            if(dis>dist[node]) continue ;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int ew = it.second ;

                if(dis+ew < dist[adjNode]){
                    dist[adjNode] = dis+ew ;
                    pq.push({dist[adjNode] , adjNode});
                    ways[adjNode] = ways[node] ;
                }

                else if (dis + ew == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod ;
                }
            }
        }


        return ways[n-1] %mod ;


        
    }
};