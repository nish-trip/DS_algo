#include "test.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode smallerHead(0), largerHead(0);
        ListNode *smallerIter = &smallerHead, *largerIter = &largerHead;
        while(head){
            if(head->val < x){
                smallerIter->next = head;
                smallerIter = smallerIter->next;
            }
            else{
                largerIter->next = head;
                largerIter = largerIter->next;
            }
            head = head->next;
        }   
        largerIter->next = NULL;
        smallerIter->next = largerHead.next;
        return smallerHead.next;  
    }
};