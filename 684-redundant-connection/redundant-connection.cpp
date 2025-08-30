class Solution {
public:
    vector<int> parent ;
    vector<int> rank ;

    int find(int x){
        if( parent[x] == x) return x ;
        return parent[x] = find(parent[x]) ;
    }

    void Union(int x , int y){
        int x_parent = find(x) ;
        int y_parent = find(y) ;

        if( x_parent == y_parent ) return ;

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent ;

        }else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent ;
            
        }
        else{
            parent[x_parent] = y_parent ;
            rank[y_parent] ++ ;

        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        vector<int> ans ;
        int n = edges.size() ;
        parent.resize(n+1 );
        rank.resize(n+1 , 0) ;
        for(int i = 0 ; i<n ; i++) parent[i] = i ;


        for(auto& vec : edges){
            int u = vec[0] ;
            int v = vec[1] ;

            int u_parent = find(u) ;
            int  v_parent = find(v) ;

            if(u_parent == v_parent ) {
                ans.push_back(u) ;
                ans.push_back(v) ;
                return ans ;
            }
            Union(u , v ) ;
        }
        return {}; 
        
    }
};