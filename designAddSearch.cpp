#include "test.h"

class WordDictionary {
public:
    class Trienode{
    public:
        char data;
        int wc;
        Trienode* children[26];
    };
    Trienode* root;

    WordDictionary() {
        root = new Trienode();
        root->data = '/';
        root->wc = 0;
        for(int i=0; i<26; i++){
            root->children[i] = NULL;
        }   
    }

    Trienode* getNode(char c){
        Trienode* node = new Trienode();
        node->data = c;
        node->wc = 0;
        for(int i=0; i<26; i++){
            node->children[i] = NULL;
        }
        return node;
    }
    
    void addWord(string word) {
        Trienode* cur = root;
        for(char c: word){
            int index = c-'a';
            if(!cur->children[index]){
                cur->children[index] = getNode(c);
            }
            cur = cur->children[index];
        }
        cur->wc++;
    }
    
    bool search(string word) {
        return search(word, 0);
    }

    bool search(string word, int index){
        Trienode* node = root;
        for(int i=index; i<word.size() && node != NULL; i++){
            if(word[i] != '.'){ // if the current charcter is a letter
                int index = word[i]-'a';
                node = node->children[index];   // if children[index] is NULL then we we break out of the for loop sice node==NULL
            }
            else{   // if the character is '.' then we have to use recursion
                Trienode* temp = node;
                for(int j=0; j<26; j++){
                    node = temp->children[j];
                    if(node!= NULL && search(word, i+1)){
                        return true;
                    }
                }
            }
        }
        return node && node->wc;
    }
};
