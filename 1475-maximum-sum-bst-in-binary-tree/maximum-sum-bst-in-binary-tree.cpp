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

class var{
public:
   int maxi;
   int mini;
   int sum;
   var(int maxi,int mini,int sum){
       this->maxi=maxi;
       this->mini=mini;
       this->sum=sum;
   } 
};
class Solution {
public:
    // optimised the approach  
    var ans(TreeNode* root,int &res){
        if(root==NULL){
            return var(INT_MIN,INT_MAX,0);
        }
        var a=ans(root->left,res);
        var b=ans(root->right,res);
        if(a.maxi<root->val && b.mini>root->val){
            int sum=a.sum+b.sum+root->val;
            res=max(res,sum);
            return var(max(root->val,b.maxi),min(root->val,a.mini),sum);
        }
        return var(INT_MAX,INT_MIN,0);
    }
    int maxSumBST(TreeNode* root){
        int res=0;
        ans(root,res);
        return res;
    
        
    }
};

/*

BST check = O(size of subtree)
Sum = O(size of subtree)

tc  O(n²)
Sc O(h)
*/