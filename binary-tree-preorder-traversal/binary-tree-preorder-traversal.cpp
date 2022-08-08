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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
//         RECURSIVE PREORDER
        // if(root)
        // {
        //     res.push_back(root->val);
        //     preorderTraversal(root->left);
        //     preorderTraversal(root->right);
        // }
        // return res;
//         ITERATIVE PREORDER=======================
        stack<TreeNode *> st;
        TreeNode* t=root;
        while(t || !st.empty())
        {
            if(t)
            {
                res.push_back(t->val);
                st.push(t);
                t=t->left;
            }
            else
            {
                t=st.top();
                st.pop();
                t=t->right;
            }
        }
        return res;
    }
};