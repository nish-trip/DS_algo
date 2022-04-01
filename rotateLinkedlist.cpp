#include "test.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        int len =1;
        ListNode* tail = head;
        while(tail->next){
            len++;
            tail = tail->next;
        }      
        k%= len;
        if(!k){
            return head;
        }
        ListNode* newTail = tail;
        int steps = len-k;
        tail->next = head;
        while(steps--){
            tail = tail->next;
        }
        ListNode* newHead = tail->next;
        tail->next = NULL;
        return newHead;
    }
};