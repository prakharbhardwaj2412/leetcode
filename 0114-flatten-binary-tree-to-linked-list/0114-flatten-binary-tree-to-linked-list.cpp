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
// There are three solutions for this:
// 1) RECURSIVE APPROACH
class Solution {
public:
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

// // 2) ITERATIVE APPROACH
// class Solution {
// public:
//     void flatten(TreeNode* root) {
        
//     }
// };

// // 3) MORRIS TRAVERSAL APPROACH
// class Solution {
// public:
//     void flatten(TreeNode* root) {
        
//     }
// };