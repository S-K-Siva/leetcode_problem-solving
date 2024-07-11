#include<bits/stdc++.h>
using namespace std;

class MyListNode{
    public:
    int val;
    MyListNode *next;
    MyListNode(int x) : val(x),next(nullptr){}
};

class MyLinkedList {
public:

    MyListNode *result;
    
    MyLinkedList() {
        result = nullptr;
    }
    
    int get(int index) {
        int trackIndex = 0;
        MyListNode *track;
        track = result;
        while(track != NULL){
            if(index == trackIndex){
                return track->val;
            }
            ++trackIndex;
            track = track->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        MyListNode *newNode;
        newNode = new MyListNode(val);
        newNode->next = result;
        result = newNode;
    }
    
    void addAtTail(int val) {
        MyListNode *newNode,*track;
        newNode = new MyListNode(val);
        track = result;
        if(track == NULL){
            addAtHead(val);
            return;
        }
        
        while(track && track->next != NULL){
            track = track->next;
        }
        track->next = newNode;
        track = track->next;
    }
    
    void addAtIndex(int index, int val) {
        int trackIndex = 0;
        MyListNode *track,*newNode;
        newNode = new MyListNode(val);
        track = result;
        if(index == 0){
            addAtHead(val);
            return;
        }
        while(track != NULL){
            if(trackIndex+1 == index){
                MyListNode* newNodeNext;
                newNodeNext = track->next;
                track->next = newNode;
                newNode->next = newNodeNext;
                break;
            }
            ++trackIndex;
            track = track->next;
        }
    }
    
    void deleteAtIndex(int index) {
        int trackIndex = 0;
        MyListNode *newResult;
        if(index == 0){
            newResult = result->next;
            result = newResult;
        }
        
        MyListNode *track;
        track = result;

        while(track != NULL){
            if(trackIndex+1 == index){
                if(track->next == NULL){
                    return;
                }
                track->next = track->next->next;
                break;
            }
            ++trackIndex;
            track = track->next;
        }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */