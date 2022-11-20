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
private:
    void generatePath (TreeNode* root, vector<string> &ans, string str) {
        if(!root->left && !root->right) {
            ans.push_back(str);
            return;
        }
        
        string tmp = "";
        if(root->left) {
            tmp = "->" + to_string(root->left->val);
            generatePath(root->left, ans, str+tmp);
        }
        if(root->right) {
            tmp = "->" + to_string(root->right->val);
            generatePath(root->right, ans, str+tmp);
        }
        
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        generatePath(root, ans, to_string(root->val));
        return ans;
    }
};