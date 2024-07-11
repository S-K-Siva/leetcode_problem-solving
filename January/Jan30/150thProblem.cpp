#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> vals;
        for(string it : tokens){
            if(it == "+" || it == "-" || it == "*" || it == "/"){
                // symbol received
                int n2 = vals.top();
                vals.pop();
                int n1 = vals.top();
                vals.pop();
                
                if(it == "+") vals.push(n1 + n2);
                if(it == "-") vals.push(n1 - n2);
                if(it == "/") vals.push(n1 / n2);
                if(it == "*") vals.push(n1 * n2);
                
            }else{
                vals.push(stoi(it));
            }
    }
             int num = vals.top();
        return num;
        }
       
    
};