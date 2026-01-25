/*
One is moving right (+)
The next is moving left (-)
creates a  last-in, first-out behavior

Pushing right-moving asteroids onto a stack 
Asteroids only collide when left-moving asteroid appears
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // using stack 
        int n = asteroids.size() ;
        stack<int> st ;
        

        for( int a : asteroids){
            if(a > 0){ // right moving(+)
                st.push(a) ; // no collisions push it 
            } 
            else{
                // left moving(-) 
                // collision 
                // destroy smaller right moving asteroids
                while(!st.empty() && st.top() >0 && st.top() < -a){
                    st.pop() ;
                }
                // equal size collision
                if(!st.empty() && st.top() == -a){
                    st.pop() ;
                }

                // larger right moving survives
                // left moving current asteroid gets collapse 
                else if(!st.empty() && st.top() > -a){
                    continue ;
                }
                else{ // current asteroid survive
                    st.push(a) ;
                }
            }
        }

        vector<int> ans(st.size());
        for(int i = st.size() -1 ; i>=0 ; i--){
            ans[i] = st.top() ;
            st.pop() ;
        }

        return ans ;
        
    }
};

// TC-->O(N)  SC--> O(N)  