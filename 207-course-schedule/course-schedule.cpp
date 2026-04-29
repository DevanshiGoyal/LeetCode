class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // using kahns algorithm 
        vector<vector<int>>adj(numCourses);
        //vector<int> ans ;
        vector<int> indegree(numCourses , 0) ;

        for(auto courses : prerequisites){
            adj[courses[1]].push_back(courses[0]) ;
            
        }

        for(int i=0 ; i<numCourses ; i++){
            for(auto&it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q ;
        int count = 0;
        for(int i = 0 ; i<numCourses ; i++){
            if(indegree[i] == 0){
                count++;
                q.push(i) ;
            }
        }

        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            //ans.push_back(node) ;

            for(auto it : adj[node]){
                indegree[it] --  ;
                if(indegree[it] == 0){
                    q.push(it) ;
                    count++;
                }
            }
        }
        return count==numCourses;
        //return ans.size()==numCourses; //it means loop does not exist
        //if loop exist then there are less elements in ans vector  
        
    }
};

//Time Complexity: O(V+E)-->  Visit each course and its prerequisites once.
// Space Complexity: O(V+E) Adjacency list + visited arrays