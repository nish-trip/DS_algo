#include "test.h"

class Solution {
public:
    struct trienode{
        char data;
        int wc;
        string word;
        trienode* child[26];
    };
    
    trienode* root;
    
    void init(){
        root = new trienode();
        root->data = '/';
        root->wc = 0;
        root->word = "";
        for(int i=0; i<26; i++){
            root->child[i] = NULL;
        }
    }
    
    trienode* getnode(char c){
        auto node = new trienode();
        node->data = c;
        node->wc = 0;
        root->word = "";
        for(int i=0; i<26; i++){
            node->child[i] = NULL;
        }    
        return node;
    }
    
    void insert(string w){
        auto node = root;
        for(char c: w){
            int index = c-'a';
            if(!node->child[index]){
                node->child[index] = getnode(c);
            }
            node = node->child[index];
        }
        node->wc++;
        node->word = w;
    }
    
    string search(){
        queue<trienode*>q;
        q.push(root);
        string ans = "";
        while(!q.empty()){
            trienode* front = q.front();
            q.pop();
            for(int i=25; i>=0; i--){
                if(front->child[i] && front->child[i]->word.size()>0){
                    ans = front->child[i]->word;
                    q.push(front->child[i]);
                }
            }
        }
        return ans;
    }
    
    string longestWord(vector<string>& words) {
        init();
        for(string word: words){
            insert(word);
        }
        return search();
    }
};