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
    void inOrder(TreeNode* root, vector<TreeNode*> &arr)
    {
        if(!root) return;
        inOrder(root->left, arr);
        arr.push_back(root);
        inOrder(root->right, arr);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return NULL;
        vector<TreeNode*> arr;
        inOrder(root, arr);
        TreeNode* t; TreeNode* r=arr[0];
        cout<<arr.size()<<endl;
        for(int i=0; i<arr.size()-1; i++)
        {
            t=arr[i];
            cout<<i<<" "<<t->val<<endl;
            t->left=NULL;
            t->right=arr[i+1];
            cout<<t->right->val<<endl;
            t->right->left=t->right->right=NULL;
        }
        
        return r;
        
    }
};