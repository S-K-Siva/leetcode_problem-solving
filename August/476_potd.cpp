#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        if(num == 2) return 1;
        string bin = "";
        int n = num;
        while(n){
            if(n%2)
                bin += '1';
            else    
                bin += '0';
            n/=2;
        }
        
        int result = 0;
        for(int i = 0;i<bin.size();i++){
            if(bin[i] == '0'){
                result += pow(2,i);
            }
        }
        return result;
    }
};
