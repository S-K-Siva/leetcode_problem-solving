#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // unordered_map<ListNode *,int> mp;
        // ListNode *temp;
        // temp = head;
        // while(temp){
        //     if(mp[temp]) return true;
        //     mp[temp] = 1;
        //     temp = temp->next;
        // }
        // return false;
   
        ListNode *slow,*fast;
        slow = head;
        if(head == NULL) return false;
        fast = head->next;

        while(fast != NULL && slow != NULL){
            slow = slow->next;
            if(fast->next)
                fast = fast->next->next;
            else
                fast = fast->next;
            if(slow == fast) return true;
        }
        return false;
    }


};