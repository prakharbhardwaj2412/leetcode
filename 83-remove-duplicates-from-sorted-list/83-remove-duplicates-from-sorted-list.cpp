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

// FOR SORTED LINKED LIST============================================
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode *prev=NULL, *curr=NULL;
//         prev=head;
//         curr=head?head->next:NULL;
//         while(curr)
//         {
//             if(prev->val==curr->val)
//             {
//                 ListNode *t;
//                 t=curr;
//                 prev->next=curr->next;
//                 curr=curr->next;
//                 delete t;
//             }
//             else 
//             {
//                 prev=curr;
//                 curr=curr->next;
//             }
//         }
//         return head;
        
//     }
// };


// FOR UNSORTED LINKED LIST========================================
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> s;
        ListNode *prev, *curr;
        curr=head;
        while(curr)
        {
            if(s.find(curr->val)!=s.end())
            {
                prev->next=curr->next;
                delete(curr);
            }
            else
            {
                s.insert(curr->val);
                prev=curr;
            }
            curr=prev->next;
        }
        return head;
        
    }
};