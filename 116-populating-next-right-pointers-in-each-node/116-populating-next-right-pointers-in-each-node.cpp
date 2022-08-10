/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// LEVEL ORFDER TRAVERSAL
// class Solution {
// public:
//     Node* connect(Node* root) {
//         queue<Node*> q;
//         Node* t1=root;
//         Node* t2;
//         if(!t1) return NULL;
//         q.push(t1);
//         q.push(NULL);
//         while(!q.empty())
//         {
//             int n=q.size();
//             t1=q.front();
//             q.pop();
//             for(int i=0; i<n-1; i++)
//             {
//                 t2=q.front();
//                 q.pop();
//                 t1->next=t2;
//                 if(t1)
//                 {                    
//                     if(t1->left) q.push(t1->left);
//                     if(t1->right) q.push(t1->right);
//                 }
//                 t1=t2;
//             }
//             if(!q.empty()) q.push(NULL);
//         }
//         return root;
//     }
// };

// DEPTH FIRST SEARCH
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        auto L=root->left, R=root->right, N=root->next;
        if(L) L->next=R;
        if(R) {
            if(N) R->next=N->left;
            else R->next=NULL;
        }
        connect(L);
        connect(R);
        return root;
    }
};