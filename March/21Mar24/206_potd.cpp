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

    void helper(ListNode* head, queue<int> &qq){
        if(head == NULL){
            return;
        }
        qq.push(head->val);
        helper(head->next,qq);
        head->val = qq.front();
        qq.pop();
    }
    ListNode* reverseList(ListNode* head) {
        queue<int> q;
        helper(head,q);
        return head;
    }
};