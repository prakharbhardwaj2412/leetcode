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

// RECURSIVE CALCULATION OF HEIGHT
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(!root) return 0;
//         int x=maxDepth(root->left);
//         int y=maxDepth(root->right);
//         return max(x,y)+1;
        
//     }
// };


// LEVEL ORDER TRAVERSAL TO FIND HEIGHT
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        int height=0;
        q.push(root);
        while(!q.empty()) {
            int ln = q.size();
            for(int i=0; i<ln; i++) {
                auto node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            height++;
        }
        return height;
        
    }
};
