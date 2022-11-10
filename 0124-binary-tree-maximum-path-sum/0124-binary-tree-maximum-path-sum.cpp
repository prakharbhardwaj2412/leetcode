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
        int leftsum = height(root->left, maxI);
        int rightsum = height(root->right, maxI);
        leftsum = max(0, leftsum);
        rightsum = max(0, rightsum);
        maxI=max(maxI, root->val+leftsum+rightsum);
        return root->val+max(leftsum, rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        height(root, maxi);
        return maxi;
    }
};