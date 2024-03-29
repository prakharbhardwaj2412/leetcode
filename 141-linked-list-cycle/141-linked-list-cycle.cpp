/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode *p, *q;
//         p=q=head;
//         do
//         {
//             p=p!=NULL?p->next:NULL;
//             q=q!=NULL?q->next:NULL;
//             q=q!=NULL?q->next:NULL;
//         } while(p && q && p!=q);
//         return (p==q && p!=0)?true:false;
        
//     }
// };


class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode*> s;
        while(head!=NULL)
        {
            if(s.find(head) != s.end())
                return true;
            s.insert(head);
            head=head->next;
        }
        return false;
    }
};