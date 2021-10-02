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

struct Compare{
    bool operator()(ListNode* a,ListNode* b){
        if(a->val>b->val) return 1;
        return 0;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& l) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        ListNode* d=new ListNode();
        ListNode* temp=d;
        for(int i=0;i<l.size();i++){
            if(l[i]!=NULL)
            pq.push(l[i]);
        }
        
        while(!pq.empty()){
            temp->next=pq.top();
            ListNode* t=pq.top()->next;
            pq.pop();
            if(t!=NULL) pq.push(t);
            temp=temp->next;
        }
        return d->next;
    }
};