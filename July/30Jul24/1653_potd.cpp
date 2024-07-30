#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumDeletions(string s) {
        // Effective
        // TC : O(N) && SC : O(N)
        stack<char> Stack;
        int n = s.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(Stack.empty()){
                Stack.push(s[i]);
            }else{
                char topElement = Stack.top();
                if(topElement == 'b' && s[i] == 'a'){
                    cnt++;
                    Stack.pop();
                }else{
                    Stack.push(s[i]);
                }
            }
        }
        return cnt;


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