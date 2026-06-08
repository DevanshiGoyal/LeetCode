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
class BSTIterator {
public:
// intution
    vector<int> inorder;
    int ptr ;

    void inorderTraversal(TreeNode*root){
        if(!root) return ;
        inorderTraversal(root->left) ;
        inorder.push_back(root->val);
        inorderTraversal(root->right);


    }
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
        ptr = 0 ;
        
    }
    
    int next() {
        return inorder[ptr++] ;
        
        
    }
    
    bool hasNext() {
        return ptr<inorder.size() ;
        
    }
};
// tc-->O(n) inorder   next() ->O(1)  hasNext() ->O(1)
//sc-->O(n)  vector to store all nodes

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */