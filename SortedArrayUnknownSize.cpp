#include "test.h"

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        // ArrayReader.get(i)
        // (2^31) - 1
        int power = 0;
        while(true){
            int index = (1<<power)-1;
            if(reader.get(index) == target){
                return index;
            }
            if((reader.get(index) == INT_MAX || target<reader.get(index))){
                break;
            }
            power++;
        }
        int left = 1<<(max(0,power-1)), right = (1<<power)-2;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(reader.get(mid) == target){
                return mid;
            }      
            if(reader.get(mid) < target){
                left = mid+1;
            }                
            else{
                right = mid-1;
            }
        }
        return -1;
    }
};