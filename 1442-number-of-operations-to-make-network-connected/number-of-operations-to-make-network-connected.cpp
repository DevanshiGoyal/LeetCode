class Solution {
public:

    vector<int> parent ;
    vector<int> rank ;
    
    int find(int x){
        if(parent[x]==x) return x ;
        return parent[x] = find(parent[x]) ;
    }

    
    void Union(int x , int y ){
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent) return ; // already in same set // no need for union 
        
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent ;
            
        }else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent ;
            
        }else{
            parent[x_parent] = y_parent ;
            rank[y_parent] ++ ;
            
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;

        int cnt = 0 ;
        for(auto& x : connections){
            int u = x[0];
            int v = x[1];
            int u_parent = find(u) ;
            int v_parent = find(v) ;
            if(u_parent == v_parent) cnt++ ; // redundant connection
            Union(u , v) ;
        }
                
            
        
        int we = -1;
        for(int i = 0; i < n; i++){
            if(parent[i] == i) we++;
        }
        if(cnt >= we ){
            return we;
        }else{
            return -1;
        }    


        
    }
};