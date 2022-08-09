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
        if(left && right)
        {
            // cout<<left->val<<" "<<right->val<<" "<<((left->val==right->val) && checkSib(left->left, right->right) && checkSib(left->right, right->left))<<endl;
            return (left->val==right->val) && checkSib(left->left, right->right) && checkSib(left->right, right->left);
        }
        if((!left && right) || (left && !right)) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        bool ans=checkSib(root->left, root->right);
        // cout<<ans;
        return ans;
    }
};