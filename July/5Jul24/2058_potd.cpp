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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL){
            return {-1,-1};
        }
        // 3pointer
        ListNode *first,*second,*third;
        first = head;
        second = head->next;
        third = head->next->next;
        int first_index,second_index, third_index;
        first_index = 0;
        second_index = 1;
        third_index = 2;
        vector<int> criticalpoints;
        int res1 = -1, res2 = -1;
        //res1 = minimum Length between critical points
        //res2 == maximum Length between critical points
        
        while(third != NULL){
            if((second->val > first->val && second-> val > third->val) || (second->val < first->val && second->val < third->val)){
                // found a critical point
                criticalpoints.push_back(second_index);
            }
            first = second;
            second = third;
            third = third->next;
            first_index = second_index;
            second_index = third_index;
            third_index = third_index+1;
        }
        for(auto it : criticalpoints){
            cout << it << " ";
        }cout << endl;
        // if there are less than 2 criticalpoints, then it's not possible 
        // either local minima or local maxima present
        if(criticalpoints.size() < 2){
            return {res1,res2};
        }
        res1 = INT_MAX; // changing -1 to INT_MAX to keep track of minimum
                        // distance of critical points

        res2 = INT_MIN; // changing -1 to INT_MIN to keep track of maximum
                        // distance of critical points

        int n = criticalpoints.size();
        // to find the minimum dis of two critical points, we sorted it 
        // to reduce O(n^2) to O(n) traversal
        sort(criticalpoints.begin(),criticalpoints.end());
        
        for(int i = n-2;i>-1;i--){
            // finding the minimum distance of any two critical poionts
            res1 = min(res1,abs(criticalpoints[i]-criticalpoints[i+1]));
            
        }
        // abs val of first element and last element of a sorted critical
        // point's index would be maximum distance of any two critical points
        res2 = max(res2,criticalpoints[n-1] - criticalpoints[0]);
        return {res1, res2};
    }
};