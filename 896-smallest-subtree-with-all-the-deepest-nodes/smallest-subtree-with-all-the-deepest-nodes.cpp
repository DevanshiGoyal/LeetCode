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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        if(!root) return nullptr ;
        
        // parent map
        unordered_map<TreeNode* , TreeNode*> parent ;

        // for BFS traversal 
        queue<TreeNode*> q ;

        q.push(root);
        parent[root] = nullptr ;

        vector<TreeNode*> lastlevel ;

        // BFS traversal

        while(!q.empty()){
            int size = q.size() ;
            lastlevel.clear();
            for(int i = 0 ; i<size ; i++){
                TreeNode* node = q.front() ;
                q.pop();
                lastlevel.push_back(node);

                if(node->left){
                    parent[node->left] = node ;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right] = node ;
                    q.push(node->right);
                }
            }
        }

        unordered_set<TreeNode*> deepest (lastlevel.begin() , lastlevel.end());

        // Move upward until one node remains 
        while(deepest.size()>1){
            unordered_set<TreeNode*> next ;
            for(auto node : deepest){
                next.insert(parent[node]) ;

            }
            deepest = next ;

        }
        return *deepest.begin() ;

        
    }
};