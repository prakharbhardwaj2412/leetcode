/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode *> q;
        TreeNode* t=cloned;
        q.push(t);
        while(!q.empty())
        {
            t=q.front();
            q.pop();
            if(t->val==target->val) return t;
            if(t->left)
            {
                q.push(t->left);
            }
            if(t->right) q.push(t->right);
            
        }
        return t;
        
    }
};