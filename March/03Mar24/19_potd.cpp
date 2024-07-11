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


    ListNode* helper(ListNode* head, int height, int target,int length){
        if(head == NULL) return head;
        if((length-height) == target){
            if(head->next != NULL)
                head->next = head->next->next;
            else
                head->next = NULL;
            return head;
        }
        helper(head->next,height+1,target,length);
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int length = 0;

        ListNode* temp;
        temp = head;

        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        if(n == 1 && length==1) return NULL;


        temp = new ListNode(-1);
        temp->next = head;

        ListNode *result;
        result = helper(temp,0,n,length);
        return result->next;
    }
};