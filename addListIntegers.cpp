#include "test.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* iter  = dummy;
        int sum = 0;// initially there is no carry over so the total sum is 0
        while(l1 || l2){
            if(l1){
                sum+= l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum+= l2->val;
                l2 = l2->next;
            }
            iter->next = new ListNode(sum%10);  // we add only the least significant part to the new node and the rest is taken as carry over
            sum/=10; // sum/10 is used to calculate the carry over which is added in the next iteration
            iter = iter->next;
        }
        if(sum){// if there is still a carry then we create a new node and append it to the end of the current list
            iter->next = new ListNode(sum);
        }
        return dummy->next;
    }
};