#include "test.h"

class LRUCache {
    int size;
    list<pair<int,int>>dll; // used to implement the doubly linked list
    unordered_map<int, list<pair<int,int>>::iterator>hash;  
public:
    LRUCache(int capacity) :size(capacity){}
    
    int get(int key) {
        if(hash.find(key) == hash.end()){   // if the key isnt present in the hash
            return -1;
        }
        else{   // push the accessed node to the front of the DLL
            dll.splice(dll.begin(), dll, hash.find(key)->second);
            return hash.find(key)->second->second;      // return the value from the hash
        }
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end()){       // if the key is already present in the hash, update its value in hash and push the node to the fromt of the DLL
            hash.find(key)->second->second = value;
            dll.splice(dll.begin(), dll, hash.find(key)->second);
            return;
        }

        if(hash.size() == size){            // if the size is full the delete the last element which happens to be the least recently used
            int keyToDel = dll.back().first;
            dll.pop_back();
            hash.erase(keyToDel);
        }
        // push the key,value pair to the front of the DLL and update the hash
        dll.push_front(make_pair(key,value));
        hash[key] = dll.begin();
    }
};

