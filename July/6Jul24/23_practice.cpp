#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:

    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *result,*track;
        result = new ListNode(-1); // optional to make first node as -1 else keep 'NULL' and add additional conditions to cope up with the result.
        track = result; // take reference of original pointer
        for(auto it : lists){
            ListNode *temp;
            temp = it;
            // traverse the the current linkedlist
            while(temp != NULL){
                // create new node that need to be inserted
                ListNode *newNode;
                newNode = new ListNode(temp->val);
                // if the new inserting value is larger than or equal to the last value of resultant linkedlist
                if(track->val <= temp->val){
                    
                    track->next = newNode;
                    track = track->next;
                    
                }
                else{
                    // find insert position
                    ListNode *finding,*newNodeNext;
                    finding = result;
                    while(finding && finding->next && finding->next->val < temp->val){
                        finding = finding->next;
                    }
                    //inserting...
                    newNodeNext = finding->next;
                    finding->next = newNode;
                    newNode->next = newNodeNext;
                    // again set track to the last node, for further insertion.. (optional)
                    track = result;
                    while(track->next != NULL){
                        track = track->next;
                    }
                }
                temp = temp->next;
            }
        }
        // ignore first element '-1', since it's an extra element to make insertion easier.
        return result->next;
    }
};