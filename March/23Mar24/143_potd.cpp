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
    void reorderList(ListNode* head) {
        vector<int> values;
        int n = 0;

        ListNode* temp;
        temp = head;
        while(temp != NULL){
            ++n;
            values.push_back(temp->val);
            temp = temp->next;
        }
        
        int first = 0;
        int second = n-1;

        temp = head;

        while(temp != NULL && temp->next != NULL){
            temp->val = values[first];
            temp->next->val = values[second];
            --second;
            ++first;
            temp = temp->next->next;
        }

        while(temp != NULL){
            temp->val = values[first];
            temp = temp->next;
            ++first;
            --second;
        }
        
    }
};