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
    void traversal(TreeNode* root, set<int> &st, unordered_map<int, int> &freq) {
        if(!root) return;
        traversal(root->left, st, freq);
        freq[root->val]++;
        st.insert(freq[root->val]);
        traversal(root->right, st, freq);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;
        set<int> st;
        traversal(root, st, freq);
        
        auto m = st.end();
        
        vector<int> ans;
        
        for(auto it : freq) {
            if(it.second == *m) ans.push_back(it.first);
        }
        
        return ans;
    }
};