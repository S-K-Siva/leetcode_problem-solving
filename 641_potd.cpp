#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    deque<int> dq;
    int maxSize;
    MyCircularDeque(int k) {
        maxSize = k;
    }
    
    bool insertFront(int value) {
        if(dq.size() < maxSize){
            dq.push_front(value);
            return true;
        }
        return false;
        
    }
    
    bool insertLast(int value) {
        if(dq.size() < maxSize){
            dq.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(dq.empty()) return false;
        dq.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(dq.empty()) return false;
        dq.pop_back();
        return true;
    }
    
    int getFront() {
        if(dq.empty()) return -1;
        return dq.front();
    }
    
    int getRear() {
        if(dq.empty()) return -1;
        return dq.back();
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return dq.size() == maxSize;
    }
};
