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
        
        ListNode* p = head, *q = head->next, *prev;
        int num = 101;
        
        while(p && q)
        {   
            if(p == head)
            {
                if(p->val == q->val)       //delete both
                {
                    num = p->val;
                    head = q->next;
                    p = q->next;
                    if(p)
                        q = p->next;
                }
                else if(p->val == num)      //also duplicate, like in {1,1,1}
                {
                    //delete p
                    if(p==head)
                        head = p->next;
                    else
                        prev->next = p->next;
                    p = p->next;
                    q = p->next;
                }
                else
                {
                    p = p->next;
                    q = p->next;
                }
                prev = head;
            }
            
            else
            {
                if(p->val == q->val)       //delete both
                {
                    num = p->val;
                    prev->next = q->next;
                    p = q->next;
                    if(p)
                        q = p->next;
                }
                else
                {
                    if(p->val == num)      //also duplicate, like in {1,1,1}
                    {
                        //delete p
                        if(p==head)
                            head = p->next;
                        else
                            prev->next = p->next;
                        p = p->next;
                        q = p->next;
                    }
                    else
                    {
                        prev = p;
                        p = p->next;
                        q = p->next;
                    }
                }
            }
        }
        
        if(p && p->val == num)
        {
            if(p==head)
                head = p->next;
            else
                prev->next = p->next;
        }
        
        return head;
    }
};