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
    void swapNodes(TreeNode* &root)
    {
        if(root)
        {
                TreeNode* temp=root->left;
                root->left=root->right;
                root->right=temp;
        }
    }
    void inOrder(TreeNode* root)
    {
        swapNodes(root);
        if(root)
        {
            inOrder(root->left);
            inOrder(root->right);    
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        // stack<TreeNode*> st;
        inOrder(root);
        
        return root;
    }
};