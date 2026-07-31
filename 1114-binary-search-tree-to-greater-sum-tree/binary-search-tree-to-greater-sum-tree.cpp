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
    vector<int> inorder;
    vector<int> sumgreater;
    int idx = 0;

    void inorderTraversal(TreeNode* root){
        if(!root) return;

        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }

    void update(TreeNode* root){
        if(!root) return;

        update(root->left);
        root->val = sumgreater[idx++];
        update(root->right);
    }

    TreeNode* bstToGst(TreeNode* root) {
        inorderTraversal(root);

        int n = inorder.size();
        sumgreater.resize(n);

        sumgreater[n-1] = inorder[n-1];

        for(int i = n-2; i >= 0; i--){
            sumgreater[i] = sumgreater[i+1] + inorder[i];
        }

        update(root);

        return root;
    }
};
/*
Time Complexity
inorderTraversal(root) → O(n)
Computing the sumgreater array → O(n)
update(root) traversal → O(n)

Total:

O(n)+O(n)+O(n)=O(n)
	​

Space Complexity
inorder vector stores all node values → O(n)
sumgreater vector stores suffix sums → O(n)
Recursive call stack during traversals → O(h), where h is the height of the tree.
Balanced BST: O(log n)
Skewed BST: O(n)

Overall auxiliary space:

O(n)+O(h)
	​


Since O(n) dominates O(h), the overall space complexity is typically written as:

O(n)
	​

Summary
Time Complexity: O(n)
Space Complexity: O(n) (or more precisely O(n + h))
*/