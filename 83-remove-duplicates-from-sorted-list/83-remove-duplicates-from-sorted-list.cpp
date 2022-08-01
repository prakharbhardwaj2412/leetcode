/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// FOR SORTED LINKED LIST
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev=NULL, *curr=NULL;
        prev=head;
        curr=head?head->next:NULL;
        while(curr)
        {
            if(prev->val==curr->val)
            {
                ListNode *t;
                t=curr;
                prev->next=curr->next;
                curr=curr->next;
                delete t;
            }
            else 
            {
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
        
    }
};


// FOR UNSORTED LINKED LIST========================================
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode *p=head, *q=NULL, *prev=NULL;
        
//         while(p)
//         {
//             prev=p;
//             q=p->next;
//             while(q)
//             {
//                 ListNode *t;
//                 if(p->val==q->val)
//                 {
//                     prev->next=q->next;
//                     t=q;
//                     q=q->next;
//                     delete t;
//                 }
//                 else 
//                 {
//                     prev=q;
//                     q=q->next;
//                 }
//             }
//             p=p->next;
//         }
//         return head;
        
//     }
// };