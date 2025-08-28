class Solution {
public:
    // recursion 
    vector<vector<int>> result ;

    void solve(int start , int n , int k , vector<int>& temp){
        if( k == 0){
            result.push_back(temp) ;
            return ;
        }
        if(start>n){
            return ;
        }

        // taken the element
        temp.push_back(start) ;
        // explore
        solve(start+1 , n , k-1 , temp);
        // not taken 
        temp.pop_back();
        // explore 
        solve(start+1 , n , k , temp);

        }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp ;

        solve(1 , n , k , temp) ;

        return result ;
        
    }
};

//Time complexity: O(nCk)
//Space complexity: O(k)