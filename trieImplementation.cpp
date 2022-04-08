#include "test.h"

class Trie {
public:
    struct Trienode{
        char data;
        int wc;
        Trienode* child[26];
    };
    Trienode* root;
    Trie() {
        root = new Trienode() ;
        root->data = '/';
        root->wc = 0;
        for(int i=0; i<26; i++){
            root->child[i] = NULL;
        }
    }

    Trienode* getNode(char c){
        Trienode* node = new Trienode();
        node->data = c;
        node->wc = 0;
        for(int i=0; i<26; i++){
            node->child[i] = NULL;
        }
        return node;
    }
    
    void insert(string word) {
        Trienode* cur = root;
        int index;
        for(char c: word){
            index = c-'a';
            if(cur->child[index] == NULL){
                cur->child[index] = getNode(c);
            }
            cur = cur->child[index];
        }
        cur->wc++;
    }
    
    bool search(string word) {
        Trienode* cur = root;
        for(char c: word){
            int index = c-'a';
            if(cur->child[index] == NULL){
                return false;
            }
            cur = cur->child[index];
        }
        return cur->wc;
    }
    
    bool startsWith(string prefix) {
        Trienode* cur = root;
        for(char c: prefix){
            int index = c-'a';
            if(cur->child[index] == NULL){
                return false;
            }
            cur = cur->child[index];
        }
        return true;
    }
};