#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int zeros = 0;
        int ones = 0;
        queue<int> sandq;
        for(int i = 0;i<students.size();i++){
            if(students[i] == 0) zeros++;
            else ones++;
            q.push(students[i]);
        }


        for(int i= 0;i<sandwiches.size();i++){
            sandq.push(sandwiches[i]);
        }


        while(!q.empty()){
            if(q.front() == sandq.front()){
                if(q.front() & 1){
                    --ones;
                }else{
                    --zeros;
                }
                q.pop();
                sandq.pop();

            }else{
                if(zeros == 0 && sandq.front() == 0) return q.size();
                if(ones == 0 && sandq.front() == 1) return q.size();
                int element = q.front();
                q.pop();
                q.push(element);
            }
        }
        return 0;

    }
};