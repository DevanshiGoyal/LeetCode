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
    TreeNode* searchBST(TreeNode* root, int val) {

        while(root != nullptr && root->val != val){

            if(val < root->val){ // smaller move to left 
                root = root->left ;
            }else{
                root = root->right ; //greater move to right 
            }
        }

        // root val is equal to target val 
        return root ;
        
    }

};
/*' TC--> O(log N), Each step eliminates half of the tree, just like binary search , in the worst case (unbalanced tree), it could be O(N)

SC--> O(1),Iterative solution - constant space , no recursion stack is there
*/