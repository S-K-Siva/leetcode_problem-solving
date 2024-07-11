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
    
    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0;
        ListNode* temp;
        temp = head;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        ListNode *temp2;
        temp = head;
        temp2 = head;
        int index = 1;
        while(temp != NULL){
            if(index == k){
                break;
            }
            ++index;
            temp = temp->next;
        }

        int swapIndex = length - k + 1;
        index = 1;
        temp2 = head;
        while(temp2 != NULL){
            if(index == swapIndex){
                break;
            }
            ++index;
            temp2 = temp2->next;
        }
        int swapping = temp->val;
        temp->val = temp2->val;
        temp2->val = swapping;
        return head;
    }
};