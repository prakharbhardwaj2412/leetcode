//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    Node* markParent(Node* root, unordered_map<Node*, Node*> & parent_track, int target) {
        queue<Node*> q;
        q.push(root);
        Node* tar;
        while(!q.empty()) {
            Node* current = q.front(); q.pop();
            if(current->data == target) tar = current;
            if(current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
        return tar;
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(!root->left && !root->right) return 0;
        unordered_map<Node*, Node*> parent_track;
        Node* tar = markParent(root, parent_track, target);
        
        queue<pair<Node*, int>> q;
        q.push({tar, 0});
        
        unordered_map<Node*, bool> visited;
        visited[tar] = true;
        
        int time = 0;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i< size; i++) {
                int tmp = q.front().second;
                Node* current = q.front().first; q.pop();

                if(current->left && !visited[current->left]) {
                    q.push({current->left, tmp+1});
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    q.push({current->right, tmp+1});
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    q.push({parent_track[current], tmp+1});
                    visited[parent_track[current]] = true;
                }
                time = max(time, tmp);
            }
    //         time++;
        }
        return time;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends