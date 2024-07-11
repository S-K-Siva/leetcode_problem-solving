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
        unordered_map<ListNode *,int> mp;
        ListNode *temp;
        temp = head;
        while(temp){
            if(mp[temp]) return true;
            mp[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};