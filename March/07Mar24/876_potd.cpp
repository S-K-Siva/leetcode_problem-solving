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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        int mid = arr.size()/2;
        int iter = 0;
        while(temp && iter < mid){
            iter += 1;
            temp = temp->next;
        }
        return temp;
    }
};