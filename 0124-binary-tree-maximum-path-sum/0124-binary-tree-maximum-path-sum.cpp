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
    int height(TreeNode* root, int &maxI) {
        if(!root) return 0;
        int left = max(0, height(root->left, maxI));
        int right = max(0, height(root->right, maxI));
        maxI=max(maxI, root->val + left + right);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        height(root, maxi);
        return maxi;
    }
};