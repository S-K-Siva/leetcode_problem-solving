#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        /*
            3 Approaches
            -------------
            1) Stack -> Effective && not optimal
                TC : O(N)
                SC : O(N)
            2) Two pointer -> Not Effective && optimal
                TC : O(N)
                SC : O(1)
            3) Couting -> Effective && Optimal
                TC : O(N)
                SC : O(1)
        */
        
        // Effective
        // TC : O(N) && SC : O(N)
        // stack<char> Stack;
        // int n = s.size();
        // int cnt = 0;
        // for(int i = 0;i<n;i++){
        //     if(Stack.empty()){
        //         Stack.push(s[i]);
        //     }else{
        //         char topElement = Stack.top();
        //         if(topElement == 'b' && s[i] == 'a'){
        //             cnt++;
        //             Stack.pop();
        //         }else{
        //             Stack.push(s[i]);
        //         }
        //     }
        // }
        // return cnt;
        
        // Optimal Solution and Effective...
        int bCount = 0,res = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i] == 'b') bCount++;

            else res = min(res + 1,bCount); // counting the 'ba' pairs 
        }
        return res;


        // Using Stack is the effective solution of this problem since we able to get O(N) time and O(1) space through two pointers..

        // Ineffective , but efficient
        // TC : O(N) && SC : O(1)
    //     int front = 0;
    //     int rear = 1;
    //     int n = s.size();
    //     int cnt = 0;
    //     while (front < rear && rear < n) {
    //         if (s[front] == 'b' && s[rear] == 'a') {
    //             cnt++;
    //             //erasing 'ba' occurances...
    //             s.erase(front, 2);
                
    //             front = 0;
    //             rear = 1;

    //             // updating string size to overcome overlapping
    //             n = s.size();
    //         } else if (s[front] == s[rear]) {
    //             rear++;
    //             front++;
    //         } else {
    //             front = rear;
    //             rear = front + 1;
    //         }
    //     }
    //     return cnt;
    }
};