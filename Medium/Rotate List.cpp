class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        int n = 0;
        ListNode* p=head, *q=head;
        
        if(p == NULL)
            return NULL;
        
        while(p->next)
        {
            n++;
            p = p->next;
        }
        cout<<n;
        k = k%(n+1);
        
        int c = n-k;
        while(q && c)
        {
            q=q->next;
            c--;
        }
        
        p->next = head;
        head = q->next;
        q->next = NULL;
        
        return head;
    }
};