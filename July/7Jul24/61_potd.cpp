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

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL){
            return NULL;
        }else if(head->next == NULL){
            return head;
        }
        int length = 0;
        ListNode *findLength;
        findLength = head;
        while(findLength != NULL){
            ++length;
            findLength = findLength->next;
        }
        k%=length; // to overcome the overflow values
        ListNode *result;
        result = head;
        for(int i = 0;i<k;i++){
            ListNode *newNode,*track;
            newNode = new ListNode(-1);
            newNode->next = result;
            track = newNode;
            // get last node
            while(track && track->next && track->next->next != NULL){
                track = track->next;
            }cout << endl;
            newNode->val = track->next->val;
            track->next = NULL;
            result = newNode;;
        }
        return result;
    }
};