#include "test.h"

class RandomizedSet {
public:
    vector<int>vec;
    unordered_map<int,int>hash;
    RandomizedSet() {}
    
    bool insert(int val) {
        if(hash.find(val) != hash.end()){
            return false;
        }
        vec.push_back(val);
        hash[val] = vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(hash.find(val) == hash.end()){
            return false;
        }
        auto itr = hash.find(val);
        vec[itr->second] = vec.back();
        vec.pop_back();
        hash[vec[itr->second]] = itr->second;
        hash.erase(val);
        return true;
    }
    
    int getRandom() {
        int index = rand()%vec.size();
        return vec[index];
    }
};