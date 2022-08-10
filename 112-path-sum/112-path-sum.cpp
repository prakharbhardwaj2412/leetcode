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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)  return 0;
        int target = targetSum - root->val;
        if(root->left == NULL  && root-> right  == NULL){
            return  target == 0;
        }
        
        bool left = hasPathSum(root->left, target);
        bool right = hasPathSum(root->right, target);
        return left || right;
    }
};