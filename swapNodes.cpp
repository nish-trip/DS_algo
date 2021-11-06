#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }      
        ListNode* h2 = head->next;
        ListNode* rem = head->next->next;
        h2->next  = head;
        head->next = swapPairs(rem);
        return h2;
    }
};
