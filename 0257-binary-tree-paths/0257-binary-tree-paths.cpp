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
    void generatePath (TreeNode* root, vector<int> &tmp, vector<vector<int>> &arr) {
        if(!root) return;
        if(!root->left && !root->right) {
            tmp.push_back(root->val);
            arr.push_back(tmp);
            tmp.pop_back();
            return;
        }
        
        tmp.push_back(root->val);
        generatePath(root->left, tmp, arr);
        generatePath(root->right, tmp, arr);
        tmp.pop_back();
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        vector<int> tmp;
        vector<vector<int>> arr;
        generatePath(root, tmp, arr);
        for(int i = 0; i < arr.size(); i++) {
            string str = "";
            str += to_string(arr[i][0]);
            for(int j = 1; j < arr[i].size(); j++) {
                str += "->";
                str += to_string(arr[i][j]);
            }
            ans.push_back(str);
        }
        return ans;
    }
};