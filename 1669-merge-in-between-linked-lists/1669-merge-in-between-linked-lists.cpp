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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *list2_tail=list2, *p=list1;
        while(list2_tail->next) list2_tail=list2_tail->next;
        
        
        for(int i=1; i<a; i++)
        {
            p=p->next;
        }
        ListNode *t=p->next;
        p->next=list2;
        p=t;
        for(int i=a; i<b; i++)
        {
            p=p->next;
        }
        list2_tail->next=p->next;
        return list1;
    }
};