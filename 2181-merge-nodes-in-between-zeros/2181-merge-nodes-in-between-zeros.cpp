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
// ITERATIVE
// class Solution {
// public:
//     ListNode* mergeNodes(ListNode* head) {
//         ListNode *curr=head->next, *zero=head;
//         int sum=0;
        
//         while(curr)
//         {
//             if(curr->val==0)
//             {
//                 curr->val=sum;
//                 sum=0;
//                 zero->next=curr;
//                 zero=curr;
//                 curr=curr->next;
//             }
//             else
//             {
//                 sum=sum+curr->val;
//                 ListNode *t=curr;
//                 curr=curr->next;
//                 delete(t);
//             }
//         }
//         zero=head;
//         head=head->next;
//         delete(zero);
//         return head;
        
//     }
// };

// RECURSIVE
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head->next) return nullptr;
        ListNode *ptr=head->next;
        int sum=0;
        
        while(ptr->val!=0) 
        {
            sum+=ptr->val; 
            ptr=ptr->next;
        }
        head->next->val=sum;
        head->next->next=mergeNodes(ptr);
        return head->next;
        
    }
};