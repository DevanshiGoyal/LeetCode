class Solution {
public:
    typedef pair<int,int>p; 
    int dj(int src, vector<vector<p>>&adj, int val, int n){
        vector<int>dist(n, 1e9);
        priority_queue<p, vector<p>, greater<p>>pq;
        pq.push({0, src});
        dist[src]=0;
        while(!pq.empty()){
            int node= pq.top().second;
            int d= pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjnode= it.first;
                int cost= it.second;
                if(d + cost < dist[adjnode]){
                    dist[adjnode]= d + cost;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        int c=0;
        for(int i=0; i<dist.size(); i++){
            if(dist[i] <= val) c++;
        }
        return c-1;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //adj list
        vector<vector<p>>adj(n);
        for(int i=0; i<edges.size(); i++){
            auto it= edges[i];
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int>cnt(n, 0);
        for(int i=0; i<n; i++){
            int ans= dj(i, adj, distanceThreshold, n );
            cnt[i]= ans;
        }
        int mini= INT_MAX;
        int city=-1;
        for(int i=0; i<cnt.size(); i++){
            if(cnt[i] <= mini){ //update even if its equal to mini -> as we need bigger i (city) value
                mini= cnt[i];
                city=i;
            }
        }
        return city;
        
    }
};
/*
Intuition
For every city, we need to know how many other cities can be reached with a shortest path distance <= distanceThreshold.

Since the graph has weighted edges, Dijkstra's algorithm is a natural choice for finding shortest paths from a source node to all other nodes.

So, instead of trying to find the answer directly, we can:

Run Dijkstra from each city.
Count how many cities are reachable within the threshold distance.
Store this count for every city.
Choose the city with the smallest reachable count.
(If multiple cities have the same minimum count, we return the city with the greatest index)

Approach
Build an adjacency list from the given edges.
For every city i:
-Run Dijkstra's algorithm with i as the source.
-Compute the shortest distance to all other cities.
-Count the number of cities whose distance is at most distanceThreshold.
-Return count-1 (Exclude the source city itself from the count)
Store the count for each city.
Traverse all counts and keep track of:
-The minimum reachable count found so far.
-The corresponding city index.
-Update the answer even when the count is equal to the current minimum so that the larger city index is chosen in case of a tie.


Complexity
Time complexity:
Running Dijkstra once takes O(E log V).
Since we run it for all n cities, the total complexity is:
O(V × E log V)
Space complexity:
Adjacency list: O(E)
Distance array: O(V)
Priority queue: O(V)
Overall: O(V + E)

*/