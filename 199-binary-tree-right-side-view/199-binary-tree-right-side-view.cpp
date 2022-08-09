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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root)
        {
            q.push(root);
        }
        while(!q.empty())
        {
            int n=q.size();
            
            for(int i=0; i<n; i++)
            {
                root=q.front();
                if(i==0) res.push_back(root->val);
                q.pop();
                if(root->right) q.push(root->right);
                if(root->left)q.push(root->left);
            }
        }
        return res;
    }
};