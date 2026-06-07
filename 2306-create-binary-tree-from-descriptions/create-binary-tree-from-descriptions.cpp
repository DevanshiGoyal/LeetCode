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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        // to store created nodes

        unordered_map<int , TreeNode*> mp ;
        // hashmap to track parent 
        unordered_map<int , int> root ;
        // 0 node not processed  // 1 node is currently root  // -1 has a parent 

        for(auto& it : descriptions){
            int parent = it[0] ;
            int child = it[1] ;
            int isLeft = it[2] ;

            if(mp[parent] == 0){
                TreeNode* temp = new TreeNode(parent);
                mp[parent] = temp ;

            }

            if(mp[child] == 0){
                TreeNode* temp = new TreeNode(child);
                mp[child] = temp ;

            }

            if(isLeft == 1){
                mp[parent]->left = mp[child] ;
            }
            else{
                mp[parent]->right = mp[child] ;
            }

            if(root[parent] != -1){  // parent nhi h 
                root[parent] = 1 ;   // parent bana diya 
            }

            root[child] = -1 ;  // is node ka parent h 
        }

        int value = 0;

        for (auto &it : root) {
            if (it.second == 1) {
                value = it.first;
                break;
            }
        }

        return mp[value];  // vo rrot node return kr dega 
        
    }
};