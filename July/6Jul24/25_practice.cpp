#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

// using vector
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1) return head;
        ListNode *res,*track;
        res = new ListNode(-1);
        track = res;

        ListNode *headTrack;
        headTrack = head;
        vector<int> values;
        while(headTrack != NULL){
            if(values.size() != k){
                values.push_back(headTrack->val);
                headTrack = headTrack->next;
            }
            if(values.size() == k){
                reverse(values.begin(),values.end());
                // for(auto it : values){
                //     cout << it << " ";
                // }cout << endl;
                ListNode *newNode,*insertHead;
                insertHead = new ListNode(values[0]);
                newNode = insertHead;
                for(int i = 1;i<k;i++){
                    ListNode *child;
                    child = new ListNode(values[i]);
                    newNode->next = child;
                    newNode = newNode->next;
                }
                track->next = insertHead;
                while(track->next != NULL){
                    track = track->next;
                }
                values.clear();
            }
        }
        if(values.size()){
            if(values.size() == k){
                reverse(values.begin(),values.end());
            }
            // for(auto it : values){
            //     cout << it << " " << endl;
            // }
            ListNode *insertHead,*newNode;
            insertHead = new ListNode(values[0]);
            newNode = insertHead;
            for(int i = 1;i<values.size();i++){
                ListNode *child;
                child = new ListNode(values[i]);
                newNode->next = child;
                newNode = newNode->next;
            }
            track->next = insertHead;
            while(track->next != NULL){
                track = track->next;
            }
        }
        return res->next;
    }
};

// using stack
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1) return head;
        ListNode *res,*track;
        res = new ListNode(-1); // initialize the resultant pointer by 'null' or '1'
        track = res;

        ListNode *headTrack;
        headTrack = head;
        stack<int> values; // used to keep track of nodes until it reaches k nodes..
        // insertion and deletion will O(1)...
        while(headTrack != NULL){

            // until the array becomes
            if(values.size() != k){
                values.push(headTrack->val);
                headTrack = headTrack->next;
            }
            if(values.size() == k){
                
                ListNode *newNode,*insertHead;
                insertHead = new ListNode(values.top());
                newNode = insertHead;
                values.pop();
                while(!values.empty()){
                    ListNode *child;
                    child = new ListNode(values.top());
                    newNode->next = child;
                    newNode = newNode->next;
                    values.pop();
                }
                track->next = insertHead;
                while(track->next != NULL){
                    track = track->next;
                }
            }
        }
        if(values.size()){
            stack<int> temppp;
            if(values.size() < k){
                while(!values.empty()){
                    temppp.push(values.top());
                    values.pop();
                }
                values = temppp;
            }
            ListNode *insertHead,*newNode;
            insertHead = new ListNode(values.top());
            newNode = insertHead;
            values.pop();
            
            while(!values.empty()){
                ListNode *child;
                child = new ListNode(values.top());
                newNode->next = child;
                newNode = newNode->next;
                values.pop();
            }
            track->next = insertHead;
            while(track->next != NULL){
                track = track->next;
            }
        }
        return res->next;
    }
};