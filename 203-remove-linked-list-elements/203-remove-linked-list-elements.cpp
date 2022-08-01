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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p=head, *prev;
        
        while(p)
        {
            if(head->val==val)
            {
                head=p->next;
                delete(p);
                p=head;
            }
            else if(p->val==val)
            {
                prev->next=p->next;
                delete(p);
                p=prev->next;
            }
            else
            {
                prev=p;
                p=p->next;
            }
        }
        return head;
        
    }
};