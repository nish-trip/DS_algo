#include "test.h"
using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }      
        int numOfJumps = 0;
        ListNode* end = head;
        while(end->next){
            end = end->next;
            numOfJumps++;
        }
        numOfJumps = numOfJumps%2? (numOfJumps/2)+1: numOfJumps/2;
        ListNode* temp = head;
        while(numOfJumps--){
            end->next = temp->next;
            temp->next = temp->next->next;
            end->next->next = NULL;
            temp = temp->next;
            end = end->next;
        }
        return head;
    }
};