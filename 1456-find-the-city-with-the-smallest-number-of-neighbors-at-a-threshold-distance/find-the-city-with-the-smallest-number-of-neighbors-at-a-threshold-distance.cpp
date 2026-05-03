class Solution {
public:
    
    int findTheCity(int n, vector<vector<int>>& edges, int dT) {
        
        vector<vector<int>>dist(n,vector<int>(n,1000000));
        
        for(int i=0;i<n;i++)
            dist[i][i]=0;
        
        for(int i=0;i<edges.size();i++){
            
            int src=edges[i][0];
            int dst=edges[i][1];
            int wt=edges[i][2];
            
            dist[src][dst]=wt;
            dist[dst][src]=wt;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
                }
            }
        }
        
        
        int min_city=0,max_val=n;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=dT){
                    count++;
                }
            }
            //cout<<count<<"\n";
            if(count<=max_val){
                min_city=i;
                max_val=count;
            }
        }
        return min_city;
    }
};