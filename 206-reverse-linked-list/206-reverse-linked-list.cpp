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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // cout<<head->val;
        ListNode *p=head, *q=NULL, *r=NULL;
        while(p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r; //Reversing
        }
        head=q;
        return head;
        
    }
};

// NOTE: 
// 1) Three pointer(p, q, r) method
// 2) Iterative Approach