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

    void preOrder(TreeNode* root , int targetSum , int sum , vector<vector<int>> &ans, vector<int> &path){
        if(root== NULL){
            return ;
        }

        sum+=root->val;
        path.push_back(root->val) ;


        // if we reached leaf node 
        if(!root->left && !root->right){
            if(sum == targetSum) ans.push_back(path) ;
        }

        preOrder(root->left , targetSum , sum , ans ,path);
        preOrder(root->right , targetSum , sum , ans ,path);

        path.pop_back() ;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        int sum = 0 ;
        vector<vector<int>> ans;
        vector<int> path ;
        preOrder(root , targetSum , sum , ans , path) ;        
        return ans ;
        
    }
};