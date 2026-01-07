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
//T.C : O(n)
//S.C : O(n) if we consider recursion stack space, else O(1)
class Solution {
public:
    
    long M = 1e9+7;
    long totalSum = 0, maxP = 0;
    
    int findTotalSum(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftSubtreeSum  = findTotalSum(root->left);
        int rightSubtreeSum = findTotalSum(root->right);
        int sum= root->val + leftSubtreeSum + rightSubtreeSum; // S1
        
        maxP = max(maxP, (totalSum - sum) * sum); // T-S1 = S2
        
        return sum;
    }
    
    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        
        maxP = 0;
        
        // for total sum
        totalSum = findTotalSum(root);
        
        // for finding max 
        findTotalSum(root);
        
        return maxP%M;
    }
};


