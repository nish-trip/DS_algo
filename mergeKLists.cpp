#include "test.h"


class Solution {
public:
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val>b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        for(ListNode* node: Lists){
            if(node){
                pq.push(node);
            }
        }
        if(!pq.size()){
            return NULL;
        }
        ListNode *head=NULL, *cur=NULL;
        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            if(!head){
                head = cur=top;
            }
            else{
                cur->next = top;
                cur = cur->next;
            }
            if(top->next){
                pq.push(top->next);
            }
        }
        return head;
    }
};