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

// REVERSE PREORDER TRAVERSAL================
class Solution {
public:
    void rightSideViewUtil(TreeNode* node, int level, vector<int> &ans) {
        if(!node) return;
        if(ans.size() == level) ans.push_back(node->val);
        rightSideViewUtil(node->right, level+1, ans);
        rightSideViewUtil(node->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightSideViewUtil(root, 0, ans);
        return ans;
    }
};


// LEVEL ORDER ITERATIVE APPROACH
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> res;
//         queue<TreeNode*> q;
//         if(root)
//         {
//             q.push(root);
//         }
//         while(!q.empty())
//         {
//             int n=q.size();
            
//             for(int i=0; i<n; i++)
//             {
//                 root=q.front();
//                 if(i==0) res.push_back(root->val);
//                 q.pop();
//                 if(root->right) q.push(root->right);
//                 if(root->left)q.push(root->left);
//             }
//         }
//         return res;
//     }
// };

// RECURSIVE LEVEL ORDER TRAVERSAL================
// class Solution {
// public:
//     void rightViewUtil(TreeNode* root, int level, int* max_level, vector<int> &res)
//     {
//         if(!root) return;
//         if(*max_level<level)
//         {
//             res.push_back(root->val);
//             *max_level=level;
//         }
//         rightViewUtil(root->right, level+1, max_level, res);
//         rightViewUtil(root->left, level+1, max_level, res);
        
//     }
//     vector<int> rightSideView(TreeNode* root) {
//         int max_level=0;
//         vector<int> res;
//         rightViewUtil(root, 1, &max_level, res);
//         return res;
//     }
// };