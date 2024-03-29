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
// ==========================O(n*n) solution==========================
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int> &pre, int &i, int bound) {
        if(i == pre.size() || pre[i] > bound) return NULL;
        
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = bstFromPreorder(pre, i, root->val);
        root->right = bstFromPreorder(pre, i, bound);
        
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return bstFromPreorder(preorder, i, INT_MAX);
    }
};
// ==========================O(n*n) solution==========================
// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if(!root) return new TreeNode(val);
//         TreeNode *curr = root;
//         while(true) {
//             if(curr->val <= val) {
//                 if(curr->right) curr = curr->right;
//                 else {
//                     curr->right = new TreeNode(val);
//                     break;
//                 }
//             } else {
//                 if(curr->left) curr = curr->left;
//                 else {
//                     curr->left = new TreeNode(val);
//                     break;
//                 }
//             }
//         }
//         return root;
//     }
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         if(preorder.size() == 0) return NULL;
//         TreeNode* root = NULL;
//         for(int i = 0; i < preorder.size(); i++) {
//             root = insertIntoBST(root, preorder[i]);
//         }
//         return root;
//     }
// };