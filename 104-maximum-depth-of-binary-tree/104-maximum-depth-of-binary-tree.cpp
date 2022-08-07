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
        TreeNode* t=root;
        int height=0;
        q.push(t);
        q.push(NULL);
        while(!q.empty())
        {
            t=q.front();
            q.pop();
            if(!t) height++;
            
            if(t)
            {
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            else if(!q.empty())
            {
                q.push(NULL);
            }
        }
        return height;
        
    }
};
