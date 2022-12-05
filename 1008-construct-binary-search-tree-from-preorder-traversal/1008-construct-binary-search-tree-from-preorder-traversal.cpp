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
        if(!root) return new TreeNode(val);
        
        TreeNode *node = root, *pre = root;
        
        while(node) {
            pre = node;
            if(node->val < val) node = node->right;
            else if(node->val > val) node = node->left;
        }
        
        if(pre->val > val) pre->left = new TreeNode(val);
        else pre->right = new TreeNode(val);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        
        
        TreeNode* root = NULL;
        
        for(int i = 0; i < preorder.size(); i++) {
            root = insertIntoBST(root, preorder[i]);
        }
        
        return root;
    }
};