#include "test.h"

// max heap implementation


class Heap{
private:
    vector<int>pq;

    // return {maxVal, index}
    pair<int,int> maxChild(int i){
        int child1 = (i*2)+1 < pq.size()? pq[(i*2)+1]: INT_MIN;
        int child2 = (i*2)+2 < pq.size()? pq[(i*2)+2]: INT_MIN;
        if(child1 > child2){
            return make_pair(child1, (i*2)+1);
        }
        return make_pair(child2, (i*2)+2);
    }

public:
    void push(int num){
        pq.push_back(num);
        int i = pq.size()-1;
        while(i>0 && pq[i] > pq[(i-1)/2]){
            swap(pq[i], pq[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void pop(){
        if(pq.size() == 1){
            pq.pop_back();
            return;
        }
        swap(pq.front(), pq.back());
        pq.pop_back();
        int i=0;
        while(i<pq.size() && maxChild(i).first > pq[i]){
            int index = maxChild(i).second;
            swap(pq[i], pq[index]);
            i = index;
        }
    }

    int size(){
        return pq.size();
    }

    int top(){
        return pq[0];
    }
};

int kthMin(vector<int>& nums, int k){
    Heap pq;
    for(int num: nums){
        pq.push(num);
        if(pq.size() > k){
            pq.pop();
        }
    }
    return pq.top();
}


int main(){
    vector<int>vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout << kthMin(vec, 4);
}
