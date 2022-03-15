#include "test.h"

class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int, vector<int>, greater<int>>minheap;
    MedianFinder() {}
    
    void addNum(int num) {
        if(maxheap.empty()){    // first element
            maxheap.push(num);
        }

        else if(maxheap.size() == minheap.size()){      // if the size is same, insert to maxheap
            if(num<=minheap.top()){
                maxheap.push(num);
            }
            else{
                int temp = minheap.top();
                minheap.pop();
                maxheap.push(temp);
                minheap.push(num);
            }
        }

        else{       // maheap.size()+1 == minheap.size(),   insert to minheap
            if(num>= maxheap.top()){
                minheap.push(num);
            }
            else{
                int temp = maxheap.top();
                maxheap.pop();
                minheap.push(temp);
                maxheap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxheap.size() == minheap.size()){
            return (double)(maxheap.top()+minheap.top())/2;
        }
        return maxheap.top();
    }
};
