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
    long long countPairs(int n, vector<vector<int>>& edges) {

        parent.resize(n+1 );
        rank.resize(n+1 , 0) ;

        // Initially, every node is its own parent
        for(int i = 0 ; i<n ; i++) parent[i] = i ;
        
        for(auto &vec:edges){
            Union(vec[0],vec[1]);
        }


        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int parent=find(i);
            mp[parent]++;
        }

        long long ans=0;
        long long remaining=n;
        for(auto &it:mp){
            int size=it.second;
            ans+=size*(remaining-size);
            remaining-=size;
        }
        return ans;
    }
    
};