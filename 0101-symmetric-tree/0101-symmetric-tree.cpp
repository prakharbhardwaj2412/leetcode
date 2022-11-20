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
    bool checkSymmetry(TreeNode* left, TreeNode* right) {
        if(!left && !right) return left == right;
        if(left && right && left->val==right->val)
            return checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return root == NULL || checkSymmetry(root->left, root->right);
    }
};