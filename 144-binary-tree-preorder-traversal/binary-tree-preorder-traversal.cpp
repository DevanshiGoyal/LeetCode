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
    // using recursion
    void preorderTraversal(TreeNode* root, vector<int> &arr){
        // If the current node is NULL
        // (base case for recursion), return
        if(root == nullptr){
            return;
        }
        // Push the current node's
        // value into the vector
        arr.push_back(root->val);
        // Recursively traverse
        // the left subtree
        preorderTraversal(root->left, arr);
        // Recursively traverse 
        // the right subtree
        preorderTraversal(root->right, arr);
    }

    // Function to initiate preorder traversal
    // and return the resulting vector
    vector<int> preorderTraversal(TreeNode* root){
        // Create an empty vector to
        // store preorder traversal values
        vector<int> arr;
        // Call the preorder traversal function
        preorderTraversal(root, arr);
        // Return the resulting vector
        // containing preorder traversal values
        return arr;
    } 
  
};




