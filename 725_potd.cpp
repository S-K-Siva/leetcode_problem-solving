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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int Length = 0;

        ListNode *temp;
        temp = head;

        while(temp != nullptr){
            ++Length;
            temp = temp->next;
        }

        int partitions = Length/k;
        vector<ListNode*> result;
        if(partitions == 0){
            temp = head;
            while(temp != nullptr){
                ListNode *newNode;
                newNode = new ListNode(temp->val);
                result.push_back(newNode);
                temp = temp->next;
            }
            while(result.size() != k){
                result.push_back({});
            }
            return result;
        }
            temp = head;
            for(int i = 0;i<k;i++){
                ListNode *track,*sub;
                track = new ListNode(-1);
                sub = track;
                int rem = Length%k;
                int value;
                    if(Length%k != 0 && rem - i - 1 >= 0){
                        value = partitions + 1;
                    }else{
                        value = partitions;
                    }
                
                    int length = 0;
                    while(temp != nullptr){
                        ++length;
                        ListNode *newNode;
                        newNode = new ListNode(temp->val);
                        sub->next = newNode;
                        sub = sub->next;
                        temp = temp->next;
                        if(length == value){
                            break;
                        }
                    }
                    result.push_back(track->next);
                
            }
            while(result.size() != k){
                result.push_back({});
            }
            return result;
        
    }
};
