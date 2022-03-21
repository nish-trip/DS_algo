#include "test.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return NULL;
        }      
        ListNode *slow = head, *fast=head;
        bool cycle = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                cycle = true;
                break;
            }
        }
        if(!cycle){
            return NULL;
        }
        slow = head;
        while(true){
            if(slow == fast){
                return slow;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return NULL;
    }
};