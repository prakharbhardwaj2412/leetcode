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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        queue<pair<TreeNode*, double>> q;
        q.push({root, 0});
        
        int maxWidth = 0;
        
        while(!q.empty()) {
            
            int size = q.size();
            double curr_min = q.front().second;
            
            int first, last;
            for(int i = 0; i < size; i++) {
                
                TreeNode* node = q.front().first;
                double nodeIndex = q.front().second - curr_min;
                q.pop();
                
                if(i == 0) first = nodeIndex;
                if(i == size - 1) last = nodeIndex;
                
                if(node -> left) q.push({node->left, 2 * nodeIndex + 1});
                if(node->right) q.push({node->right, 2 * nodeIndex + 2});
            }
            maxWidth = max(maxWidth, last - first + 1);
        }
        return maxWidth;
        
    }
};