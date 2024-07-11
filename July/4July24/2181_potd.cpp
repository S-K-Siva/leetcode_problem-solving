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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *result, *res;
        result = new ListNode(-1);
        res = result;

        int value = 0;
        
        ListNode *temp;
        temp = head;
        while(temp != NULL){
            if(temp->val == 0){
                value = 0;
            }else{
                if(temp->next && temp->next->val == 0){
                    value += temp->val;
                    // create a new node
                    ListNode *newNode;
                    newNode = new ListNode(value);
                    res->next = newNode;
                    res = res->next;
                }else{
                    value += temp->val;
                }
            }
            temp = temp->next;
        }
        return result->next;
    }
};