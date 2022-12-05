/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
//     ================ITERATIVE
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         while(root) {
//             int curr = root->val;
            
//             if(curr > p->val && curr > q->val) 
//                 root = root->left;
//             else if(curr < p->val && curr < q->val) 
//                 root = root->right;
//             else
//                 break;
//         }
//         return root;
//     }
//     ================RECURSIVE
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        int curr = root->val;
        
        if(curr < p->val && curr < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else if(curr > p->val && curr > q->val)
            return lowestCommonAncestor(root->left, p, q);
        
        return root;
    }
};