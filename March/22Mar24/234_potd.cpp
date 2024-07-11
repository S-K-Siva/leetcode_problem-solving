#include<bits/stdc++.h>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


int init = [] {
    ios_base::sync_with_stdio(false);  cin.tie(nullptr);
    ofstream out("user.out");
    for (string s; getline(cin, s);)
        out<<(equal(s.begin()+1, s.begin()+s.size()/2, s.rbegin() + 1) ? "true\n" : "false\n");
    out.flush();
    exit(0);
    
    return 0;
}();
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string res = "";

        ListNode* temp;
        temp = head;
        while(temp != NULL){
            res += to_string(temp->val);
            temp = temp->next;
        }

        string res2 = res;

        reverse(res2.begin(),res2.end());

        return res2 == res;
    }
};