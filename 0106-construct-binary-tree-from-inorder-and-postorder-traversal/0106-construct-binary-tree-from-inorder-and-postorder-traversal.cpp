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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0) return nullptr;
        
        int value = postorder[postorder.size() - 1];
        TreeNode* newNode = new TreeNode(value);
        
        int i = 0;
        for(i = 0; i < inorder.size(); i++) if(inorder[i] == value) break;
        
        vector<int> leftIn;
        vector<int> rightIn;
        vector<int> leftPost;
        vector<int> rightPost;
        
        for(int j = 0; j < inorder.size(); j++) {
            if(j < i) leftIn.push_back(inorder[j]);
            if(j > i) rightIn.push_back(inorder[j]);
        }
        
        for(int j = 0; j < postorder.size()-1; j++) {
            if(j < i) leftPost.push_back(postorder[j]);
            if(j >= i) rightPost.push_back(postorder[j]);
        }
        
        newNode->left = buildTree(leftIn, leftPost);
        newNode->right = buildTree(rightIn, rightPost);
        
        return newNode;
    }
};