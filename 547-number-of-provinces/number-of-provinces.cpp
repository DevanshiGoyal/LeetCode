class Solution {
public:
    int n ;
    int findCircleNum(vector<vector<int>>& isConnected) {
        // bfs implementation

        n = isConnected.size() ;
        vector<int> vis(n , 0) ;
        int cnt = 0 ;
        for(int i = 0 ; i<n ; i++){
            if(!vis[i]){
                cnt++;
                bfs(i , isConnected , vis);
            }
        }

        return cnt ;

        
    }

    private :
    void bfs(int node ,vector<vector<int>>& isConnected , vector<int>& vis){

        queue<int> q ;
        q.push(node) ;
        vis[node] = 1 ;
        while(!q.empty()){
            int cur  = q.front() ;
            q.pop() ;
            for(int nei = 0 ; nei<n ; nei++){
                if(isConnected[cur][nei] == 1 && !vis[nei]){
                    q.push(nei) ;
                    vis[nei] = true ;
                }
            }
        }

    }
};