/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //Store level sums in map
    map<int , int> mp ; //{level , sum}

    void DFS(TreeNode* root , int currLevel){
        if(!root) return ;

        mp[currLevel] += root->val ;

        DFS(root->left , currLevel+1);
        DFS(root->right , currLevel+1);

    }
    int maxLevelSum(TreeNode* root) {
        // approach 2
        // using DFS traversal using a map
        //mp[level] = sum of that level
    
        DFS(root , 1) ;
        int maxSum = INT_MIN ;
        int resultLevel = 0 ;

        //Traverse map to find maximum
        for(auto &it : mp) {
            
            int level = it.first;
            int sum   = it.second;
            
            if(sum > maxSum) {
                maxSum = sum;
                resultLevel = level;
                
            
            }
        }

        return resultLevel;

        
    }
};

//TC--->O(N)    SC---> O(N) (map + recursion stack)