#include "test.h"

class FreqStack {
public:
    map<int,int>hash;
    map<int,vector<int>>freqTable;
    int maxCount = 0;
    
    FreqStack() {}
    
    void push(int val) {
        hash[val]++;
        int count = hash[val];
        if(count>maxCount){
            maxCount = count;
        }
        freqTable[count].push_back(val);
    }
    
    int pop() {
        int val = freqTable[maxCount].back();
        hash[val]--;
        freqTable[maxCount].pop_back();
        if(freqTable[maxCount].empty()){
            freqTable.erase(maxCount);
            maxCount--;
        }
        return val;
    }
};