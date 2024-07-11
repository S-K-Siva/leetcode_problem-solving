#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // sieze of Eratosthenes
    int countPrimes(int n) {
        vector<bool> primes(n+1,true);
        primes[0]=primes[1] = false;
        if(n == 0 || n == 1) return 0;
        for(long long i=2;i<n;i++){
            if(primes[i]){
                for(long long j = i*i;j<n;j+=i){
                    primes[j] = false;
                }
            }
        }
        return accumulate(primes.begin(),primes.end(),0)-1;
    }
};