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
    vector<int> inorderTraversal(TreeNode* root) {
//         RECURSIVE INORDER
        // if(root)
        // {
        //     inorderTraversal(root->left);
        //     res.push_back(root->val);
        //     inorderTraversal(root->right);
        // }
        // return res;
//         ITERATIVE INORDER=======================
        stack<TreeNode *> st;
        TreeNode* t=root;
        while(t || !st.empty())
        {
            if(t)
            {
                st.push(t);
                t=t->left;
            }
            else
            {
                t=st.top();
                st.pop();
                res.push_back(t->val);
                t=t->right;
            }
        }
        return res;
    }
};