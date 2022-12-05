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
    void inorder(TreeNode* root, int &currFreq, int &maxFreq, int &curr, vector<int> &ans) {
        if(!root) return;
        inorder(root->left, currFreq, maxFreq, curr, ans);
        if(curr == root->val) currFreq++;
        else currFreq = 1;
            
        if(currFreq > maxFreq) {
                ans.clear();
                maxFreq = currFreq;
                ans.push_back(root->val);
        }
        else if(currFreq == maxFreq) ans.push_back(root->val);
        curr = root->val;
        inorder(root->right, currFreq, maxFreq, curr, ans);
    }
    vector<int> findMode(TreeNode* root) {
        int currFreq = 0, maxFreq = 0, curr = INT_MIN;
        vector<int> ans;
        inorder(root, currFreq, maxFreq, curr, ans);
        return ans;
    }
};