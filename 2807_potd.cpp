#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* res,*result;
        res = new ListNode(-1);
        result = res;
        if(head->next){
            int val1 = head->val;
            int val2 = head->next->val;
            int gcdV = __gcd(val1,val2);
            ListNode *n1,*n2,*n3;
            n1 = new ListNode(val1);
            n2 = new ListNode(gcdV);
            n3 = new ListNode(val2);
            result->next = n1;
            n1->next = n2;
            n2->next = n3;
            result = n3;
            head = head->next;
        }else{
            return head;
        }

        while(head->next){
            int val1 = result->val;
            int val2 = head->next->val;
            int gcdV = __gcd(val1, val2);
            ListNode *n2,*n3;
            n2 = new ListNode(gcdV);
            n3 = new ListNode(val2);
            result->next = n2;
            n2->next = n3;
            result = n3;
            head = head->next;
        }

        return res->next;
    }
};
