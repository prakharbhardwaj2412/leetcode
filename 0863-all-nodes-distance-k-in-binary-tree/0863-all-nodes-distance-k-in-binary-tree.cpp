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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        map<TreeNode*, TreeNode*> mpp;
        
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->left) {
                mpp[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        
        // for(auto it : mpp) cout<<it.first->val<<"->"<<it.second->val<<endl;
        
        vector<int> ans;
        
        queue<pair<TreeNode*, int>> q2;
        set<TreeNode*> st;
        
        q2.push({target, 0});
        st.insert(target);
        
        while(!q2.empty()) {
            int size = q2.size();
            cout<<size<<endl;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q2.front().first;
                int level = q2.front().second;
                q2.pop();
                
                if(level == k) ans.push_back(node->val);
                
                if(mpp.find(node) != mpp.end() && st.find(mpp[node]) == st.end()) {
                    q2.push({mpp[node], level + 1});
                    st.insert(mpp[node]); 
                }
                if(st.find(node->left) == st.end()) {
                    if(node->left) q2.push({node->left, level + 1});
                    st.insert(node->left);
                }
                if(st.find(node->right) == st.end()) {
                    if(node->right) q2.push({node->right, level + 1});
                    st.insert(node->right);
                }
            }
        }
        
        return ans;
    }
};