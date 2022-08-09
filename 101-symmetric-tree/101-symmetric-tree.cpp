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
        if(left!=NULL ^ right!=NULL) return false;
        if(left && right)
        {
            return (left->val==right->val) && checkSib(left->left, right->right) && checkSib(left->right, right->left);
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        bool ans=checkSib(root->left, root->right);
        // cout<<ans;
        return ans;
    }
};