class Solution {
public:
    vector<int> parent , rank ;

    int find(int x){
        if(parent[x] == x){
            return x ;
        }
        return parent[x] = find(parent[x]) ;
    }

    void Union(int x , int y){
        int px = find(x) ;
        int py = find(y);

        if(px == py) return ;

        if(rank[px]<rank[py]){
            parent[px] = py ;
        }
        else if(rank[px]>rank[py]){
            parent[py] = px ;
        }else{
            parent[px] = py ;
            rank[py]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size() ;
        
        parent.resize(n) ;
        rank.resize(n , 0) ;

        for(int i =  0 ; i<n ; i++){
            parent[i] = i ;
        }
        
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(isConnected[i][j] ==1 && i!=j){
                    Union(i , j) ;
                }
            }
        }

        int ans = 0 ;
        for(int i = 0  ; i<n ; i++){
            if( parent[i] == i ){
                ans++;
            }
        }
        return ans ;
    }
};