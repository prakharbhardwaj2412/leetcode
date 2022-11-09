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

// NAIVE SOLUTION T.C. - O(n*n)
// class Solution {
// public:
//     int height(TreeNode *root, int &ans)
//     {
//         if(!root) return 0;
//         int left=height(root->left);
//         int right=height(root->right);
//         if(left>right) return left+1;
//         return right+1;
//     }
//     bool isBalanced(TreeNode* root) {
//         if(!root) return true;
//         int left=height(root->left);
//         int right=height(root->right);
//         return (abs(left-right)<=1) && isBalanced(root->left) && isBalanced(root->right);
//     }
// };

//SMART SOLUTION - O(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
    int dfsHeight(TreeNode* root) {
        if(!root) return 0;
        int lh=dfsHeight(root->left);
        if(lh==-1) return -1;
        int rh=dfsHeight(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return max(lh, rh)+1;
    }
};