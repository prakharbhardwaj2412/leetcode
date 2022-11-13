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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> nodes;
        
        while(!todo.empty()) {
            auto node = todo.front().first;
            int x = todo.front().second.first;
            int y = todo.front().second.second;
            todo.pop();
            nodes[x][y].insert(node->val);
            if(node->left) {
                todo.push({node->left, {x-1, y+1}});
            }
            if(node->right) {
                todo.push({node->right, {x+1, y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p : nodes) {
            vector<int> col;
            for(auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};