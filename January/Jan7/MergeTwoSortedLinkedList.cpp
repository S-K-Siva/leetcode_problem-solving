#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *Main = new ListNode(-1);
        ListNode *currentOne = Main;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                currentOne->next = list1;
                list1 = list1->next;
            }else{
                currentOne->next = list2;
                list2 = list2->next;
            }
            currentOne = currentOne->next;
        }

        while(list1 != NULL){
            currentOne->next = list1;
            list1 = list1->next;
            currentOne = currentOne->next;
        }

        while(list2 != NULL){
            currentOne->next = list2;
            list2 = list2->next;
            currentOne = currentOne->next;
        } 

        return Main->next;
    }
};