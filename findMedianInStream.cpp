#include "test.h"

class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>, greater<int>>minHeap;
    MedianFinder() {}
    
    void addNum(int num) {
        if(maxHeap.size() == 0){
            maxHeap.push(num);
        }
        else if(maxHeap.size() == minHeap.size()){
            if(num<minHeap.top()){
                maxHeap.push(num);
            }
            else{
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
                minHeap.push(num);
            }
        }
        else{
            if(minHeap.size() == 0){
                if(num>maxHeap.top()){
                    minHeap.push(num);
                }
                else{
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(temp);
                    maxHeap.push(num);
                }
            }
            else if(num>= minHeap.top()){
                minHeap.push(num);
            }
            else{
                if(num>maxHeap.top()){
                    minHeap.push(num);
                }
                else{
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(temp);
                    maxHeap.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top())/2;
        }
        return maxHeap.top();
    }
};