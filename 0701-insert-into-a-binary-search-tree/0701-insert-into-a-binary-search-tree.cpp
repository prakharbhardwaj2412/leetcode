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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root, *prev = root;
        
        while(node) {
            if(node->val < val) {
                prev = node;
                node = node->right;
            }
            else {
                prev = node;
                node = node->left;
            }
        }
        TreeNode* newNode = new TreeNode(val);
        if(!prev) return newNode;
        if(prev->val < val) prev->right = newNode;
        else prev->left = newNode;
        return root;
    }
};