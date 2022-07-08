#include "test.h"

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head){
            return NULL;
        }
        stack<Node*>st;
        Node* node = new Node();
        Node *cur = node, *prev = node;
        node->next = head;
        st.push(head);
        while(!st.empty()){
            cur = st.top();
            st.pop();
            cur->prev = prev;
            prev->next = cur;
            if(cur->next){
                st.push(cur->next);
            }
            if(cur->child){
                st.push(cur->child);
                cur->child = NULL;
            }
            prev = cur;
        }
        node->next->prev = NULL;
        return node->next;
    }
};