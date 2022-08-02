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
    int pairSum(ListNode* head) {
        ListNode *slow=head, *fast=head, *prev=nullptr;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            ListNode *t=slow;
            slow=slow->next;
            t->next=prev;
            prev=t;
        }
        int sum=INT_MIN;
        
        while(slow)
        {
            sum=sum>(slow->val+prev->val) ? sum:slow->val+prev->val;
            slow=slow->next;
            prev=prev->next;
        }
        
        return sum;
        
    }
};