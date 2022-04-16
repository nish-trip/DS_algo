#include "test.h"

class RandomizedCollection {
public:
    vector<int>vec;
    unordered_map<int, set<int>>hash;
    RandomizedCollection() {}
    
    bool insert(int val) {
        bool ret = hash.find(val)==hash.end();
        vec.push_back(val);
        hash[val].insert(vec.size()-1);
        return ret;
    }
    
    bool remove(int val) {
        if(hash.find(val) == hash.end()){
            return false;
        }
        // find index in which val is present
        int i = *hash[val].begin();
        // if there is only one instance of val then delete the entire record
        if(hash[val].size() == 1){
            hash.erase(val);
        }
        // if there are multiple indices then delete the first index
        else{
            hash[val].erase(hash[val].begin());
        }
        // unless the val is present at the last index of the vector
        if(i<vec.size()-1){
            vec[i] = vec.back();
            hash[vec[i]].erase(vec.size()-1);
            hash[vec[i]].insert(i);
        }
        vec.pop_back();
        return true;
    }
    
    int getRandom() {
        int index = rand()%vec.size();
        return vec[index];
    }
};