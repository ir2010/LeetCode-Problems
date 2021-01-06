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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
    
        ListNode* newHead = new ListNode(101, head);
        
        ListNode* p = newHead;
        bool dup = false;
        
        while(p && p->next && p->next->next)
        {
            ListNode* prev = p;
            while(p && p->next && p->next->next && p->next->val == p->next->next->val)
            {
                p = p->next;
                dup = true;
            }
            if(dup)
            {
                prev->next = p->next->next;
                p = prev;
            }    
            else
                p = p->next; 
            dup = false;
        }
        
        return newHead->next;
    }
};