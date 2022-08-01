/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// USING FLOYD'S CYCLE ALGO AND WITHOUT FINDING LOOP============================
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow_p, *fast_p;
        slow_p=fast_p=head;
        int count=0;
        
        do
        {
            count++;
            slow_p=slow_p!=NULL?slow_p->next:NULL;
            fast_p=fast_p!=NULL?fast_p->next:NULL;
            fast_p=fast_p!=NULL?fast_p->next:NULL;
        } while(slow_p && fast_p && slow_p!=fast_p);
        cout<<count<<endl;
        
        if(slow_p==fast_p && slow_p!=NULL)
        {
            slow_p=head;
            // cout<<slow_p->val<<" "<<fast_p->val;
            while(slow_p!=fast_p)
            {
                slow_p=slow_p->next?slow_p->next:NULL;
                fast_p=fast_p->next?fast_p->next:NULL;
            }
            return slow_p;
        }
        return NULL;
        
    }
};


// USING HASHING================================================
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_set<ListNode*> s;
//         ListNode *p=head;
//         while(p!=NULL)
//         {
//             if(s.find(p) != s.end())
//             {
//                 return p;
//             }
//             s.insert(p);
//             p=p->next;
//         }
//         return p;
        
//     }
// };