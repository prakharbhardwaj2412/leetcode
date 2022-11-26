/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string seri = "";
        if(!root) return seri;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node) {
                seri.append(to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            }
            else seri.append("#,");
        }
        cout<<seri<<endl;
        return seri;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str == "#") node->left = NULL;
            else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            
            getline(s, str, ',');
            if(str == "#") node->right = NULL;
            else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
            
            
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;