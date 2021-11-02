#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }      
        int n = 0;
        ListNode *end=head, *temp = head;
        while(end->next){
            n++;
            end = end->next;
        }
        n = n%2 == 1? n/2 +1: n/2;
        while(n--){
            end->next = temp->next;
            temp->next = temp->next->next;
            end->next->next = NULL;
            temp = temp->next;
            end = end->next;
        }
        return head;
    }
};
