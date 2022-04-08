#include "test.h"

class Solution {
public:
    struct Trienode{
        char data;
        int wc;
        Trienode* children[26];
    };

    Trienode* root;

    void init(){
        root= new Trienode();
        root->data = '/';
        root->wc = 0;
        for(int i=0; i<26; i++){
            root->children[i] = NULL;
        }
    }

    Trienode* getNode(char c){
        Trienode* node= new Trienode();
        node->data = c;
        node->wc = 0;
        for(int i=0; i<26; i++){
            node->children[i] = NULL;
        }
        return node;
    }

    void insert(string str){
        Trienode* cur= root;
        for(char c: str){
            int index = c-'a';
            if(!cur->children[index]){
                cur->children[index] = getNode(c);
            }
            cur = cur->children[index];
        }
        cur->wc++;
    }

    int prefixCount(vector<string>& words, string pref) {
        int count =0;
        init();
        insert(pref);
        Trienode* cur;
        for(string word: words){
            cur = root;
            int i=0;
            for(char c: word){
                int index = c-'a';
                i++;
                if(cur->children[index] == NULL){
                    break;
                }
                if(cur->children[index]->wc){ // or check if i==pref.size()
                    count++;
                    break;
                }
                cur = cur->children[index];
            }
        }
        return count;
    }
};

