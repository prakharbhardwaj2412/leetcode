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
    bool getPath (TreeNode* root, TreeNode* node, vector<TreeNode*> &arr) {
        if(!root) return false;
        arr.push_back(root);
        if(root->val == node->val) return true;
        
        
        
        if(getPath(root->left, node, arr) || getPath(root->right, node, arr)) return true;
        
        arr.pop_back();
        
        return false;
    } 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1;
        vector<TreeNode*> arr2;
        
        getPath(root, p, arr1);
        getPath(root, q, arr2);
        
        TreeNode* tmp = root;
        
        for(auto it : arr1) cout<<it->val<<" ";
        cout<<endl;
        for(auto it : arr2) cout<<it->val<<" ";
        
        for(int i = 0; i < min(arr1.size(), arr2.size()); i++) {
            // cout<<arr1[i]->val<<" "<<arr2[i]->val<<endl;
            if(arr1[i] == arr2[i]) tmp = arr1[i];
        }
        
        return tmp;
        
    }
};