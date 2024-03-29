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
    bool checkSib(TreeNode* left, TreeNode* right)
    {
        if(!left && !right) return true;
        if(left && right && left->val==right->val)
        {
            return checkSib(left->left, right->right) && checkSib(left->right, right->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return checkSib(root->left, root->right);
    }
};