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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* newNode;
        newNode = new ListNode(-1);
        newNode->next = head;
        map<int,int> mpp;
        for(auto it : nums){
            ++mpp[it];
        }
        ListNode* temp;
        temp = newNode;

        while(temp != nullptr){

            if(temp->next && !mpp[temp->next->val]){
                temp = temp->next;
            }else{
                ListNode* track;
                track = temp->next;

                while(track != nullptr && mpp[track->val]){
                    track = track->next;
                }
                temp->next = track;
                temp = temp->next;
            }
        }

        return newNode->next;
    }
};
