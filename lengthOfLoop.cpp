#include "test.h"

int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *slow = head, *fast = head;
    bool flag = false;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            flag = true;
            break;
        }
    }
    if(!flag){
        return 0;
    }
    int len = 0;
    while(true){
        slow = slow->next;
        len++;
        if(slow == fast){
            return len;
        }
    }
    return -1;
}