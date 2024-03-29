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

// Using length of Linked List
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* p=head;
//         int count=0;
//         while(p)
//         {
//             count++;
//             p=p->next;
//         }
//         p=head;
//         for(int i=0; i<count/2; i++) p=p->next;
//         return p;
        
//     }
// };


// Using Fast and Slow Pointer
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast, *slow;
        fast=slow=head;
        
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        
        
    }
};