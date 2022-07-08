#include "test.h"

// issue ticket(car no , color, slot number->closest to the entry)
// find all the car no. of a given color
// find the slot number using registrationNumber.
// find the registrationNumber using slot number.
// find slot numbers given a gven color
// on exit, mark the tciket and make slot avaliable


// issue ticket
// mark slot available when a car exits

class Vehicle{
    int registrationNumber;
    string color;
    Ticket* ticket;
};

class Ticket{
private:
    Vehicle* vehicle;
    Slot* slot;

public:
    Ticket(int registrationNumber, int slotNumber, string carColor){
        this->carColor = carColor;
        this->registrationNumber = registrationNumber;
        this->slotNumber = slotNumber;
    }
};

class Slot{
    int slotNumber;
    bool occupied;
    Ticket* ticket;
};

class ParkingLot{
private:
    int lotSize;
    vector<int>slots;
    vector<Ticket*>tickets;
    unordered_map<string,vector<pair<int,int>>>hash; // key: color, value: registrationNumber, slotnumber
    unordered_map<int,int>registerationHash; 

public:

    ParkingLot(int lotSize){
        this->slots.resize(lotSize, -1);
    }

    Ticket* issueTicket(int registrationNumber, string carColor, vector<int>& entrypoint){
        int slotNumber = -1;
        for(int i=0; i<lotSize; i++){
            if(slots[i] == -1){
                slotNumber = i;
            }
        }
        if(slotNumber == -1){
            printf("PARKING FULL");
            return NULL;
        }
        Ticket* newTicket = new Ticket(registrationNumber, slotNumber,  carColor);
        hash[carColor].push_back({registrationNumber, slotNumber});
        registerationHash[registrationNumber] = slotNumber;
        return newTicket;
    }

    vector<int> getCars(string color){
        vector<pair<int,int>> vec = hash[color];
        vector<int>ans;
        for(auto i: vec){
            ans.push_back(i.first);
        }
        return ans;
    }

    int findSlot(int registrationNumber){
        return registerationHash[registrationNumber];
    }

    vector<int> findSlotNumber(string color){
        vector<pair<int,int>>vec = hash[color];
        vector<int>slotNumbers;
        for(auto i: vec){
            slotNumbers.push_back(i.second);
        }
        return slotNumbers;
    }

    void carExits(int registrationNumber, string color){
        int exitCarSlot = registerationHash[registrationNumber];
        slots[exitCarSlot] = -1;
        registerationHash.erase(registrationNumber);

        //vector<int>registeredNumbers = hash[color];
        vector<pair<int,int>> temp = hash[color];
        vector<int>registeredNumbers;
        for(auto i: temp){
            registeredNumbers.push_back(i.first);
        }

        auto num = find(registeredNumbers.begin(), registeredNumbers.end(), registrationNumber);
        registeredNumbers.erase(num);
    }

};


class node{
public:
    int val;
    node* right;
    node* left;
};


void dfs(node* root, vector<int>&path, vector<vector<int>>&paths){
    if(root == NULL) return;
    path.push_back(root->val);
    if(root->left == NULL && root->right == NULL){
        paths.push_back(path);
    }
    dfs(root->left, path, paths);
    dfs(root->right, path, paths);
    path.pop_back();
}

int findSum(node* root){
    vector<int>path;
    vector<vector<int>>paths;
    dfs(root, path, paths);
    int ans = 0;
    for(auto vec: paths){
        int sum = 0;
        for(int num: vec){
            sum = (sum*10)+num;
        }
        ans+= sum;
    }
    return ans; 
}