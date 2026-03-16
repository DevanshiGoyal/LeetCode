class Solution {
public:
// using bitwise operator  
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(); // 3
        vector<vector<int>> ans ;  // output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]] power set 
        int subsets = 1<<n ; //2^3=8 length of power set 

        for(int i = 0 ;i<subsets ; i++){ // 0 1 2 3 4 5 6 7  // //000 001 010 011 100 101 110 111
            vector<int> list ; // each subset 
            for(int j=0 ; j<n ; j++){ // 0 1 2  //0--->n-1 
                if(i &(1<<j)){ // check if it is set bit  if yes then add the elment t that index ;
                    list.push_back(nums[j]);
                }
            }
            ans.push_back(list);
        }
        return ans ;
    }
};
//tc--> O(2^n * n)
//sc--> O(2^n * n)