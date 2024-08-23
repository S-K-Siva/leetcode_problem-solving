#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        vector<string> Fractions;
        vector<char> Operators;
        int n = expression.size();
        string sub = "";
        for(int i = 0; i < n; i++) {
            if(expression[i] == '+' || expression[i] == '-') {
                if(i == 0) {
                    sub += expression[i];
                    continue;
                } else {
                    if(expression[i-1] == '+' || expression[i-1] == '-') {
                        sub += expression[i];
                        continue;
                    } else {
                        Fractions.push_back(sub);
                        sub = "";
                    }
                }
                Operators.push_back(expression[i]);
            } else {
                sub += expression[i];
            }
        }
        if(sub != "") {
            Fractions.push_back(sub);
        }

        if(Fractions.size() == 1) {
            return expression;
        }


        int num, den;
        istringstream iss(Fractions[0]);
        // here we extracting the numerator and denominator (num)/(den) through istringstream.
        char slash;
        iss >> num >> slash >> den;

        int operatorIndex = 0;
        for(int i = 1; i < Fractions.size(); i++) {
            int num1, den1;
            istringstream iss(Fractions[i]);
            iss >> num1 >> slash >> den1;

            int newNum, newDen;
            if(den == den1) {
                if(Operators[operatorIndex] == '-') {
                    newNum = num - num1;
                } else {
                    newNum = num + num1;
                }
                newDen = den;
            } else {
                if(Operators[operatorIndex] == '-') {
                    newNum = (num * den1) - (num1 * den);
                } else {
                    newNum = (num * den1) + (num1 * den);
                }
                newDen = den * den1;
            }

            int gcd = __gcd(abs(newNum), newDen);
            num = newNum / gcd;
            den = newDen / gcd;

            operatorIndex++;
        }

        string result = to_string(num) + "/" + to_string(den);
        return result;
    }
};
