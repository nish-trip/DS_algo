#include "test.h"

class Trie {
public:
    class Trienode{
    public:
        char data;
        int endWord;
        int wordCount;
        Trienode* children[26];
    };

    Trienode* root;

    Trie() {
        root= new Trienode();
        root->data = '/';
        root->endWord = 0;
        root->wordCount = 0;
        for(int i=0; i<26; i++){
            root->children[i] = NULL;
        }
    }

    Trienode* getNode(char c){
        Trienode* node = new Trienode();
        node->data = c;
        node->endWord = 0;
        node->wordCount = 0;
        for(int i=0; i<26; i++){
            node->children[i] = NULL;
        }
        return node;
    }
    
    void insert(string word) {
        Trienode* cur = root;
        for(char c: word){
            int index = c-'a';
            if(!cur->children[index]){
                cur->children[index] = getNode(c);
            }
            cur = cur->children[index];
            cur->wordCount++;
        }
        cur->endWord++;
    }
    
    int countWordsEqualTo(string word) {
        Trienode* cur = root;
        for(char c: word){
            int index = c-'a';
            if(!cur->children[index]){
                return 0;
            }
            cur = cur->children[index];
        }
        return cur->endWord;
    }
    
    int countWordsStartingWith(string prefix) {
        Trienode* cur = root;
        for(char c: prefix){
            int index = c-'a';
            if(!cur->children[index]){
                return 0;
            }
            cur = cur->children[index];
        }
        return cur->wordCount;
    }
    
    void erase(string word) {
        Trienode* cur = root;
        for(char c: word){
            int index = c-'a';
            cur = cur->children[index];
            cur->wordCount--;
        }
        cur->endWord--;
    }
};