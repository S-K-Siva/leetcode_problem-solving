#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthNumber(int n, int k) {
        // TLE (42/69)
        // int cnt = 1;

        // long long int mod = 1000000007;
        // long long int number = 1;
        // for(int i = 1;i<=n;i++){
        //     number %= mod;
        //     if(cnt == k){
        //         return number;
        //     }
        //     if(number * 10 <= n){
        //         number *= 10;
        //     }else{
        //         // should not go out of boundary.
        //         while(number % 10 == 9 || number + 1 > n){
        //             number /= 10;
        //         }
        //         ++number;
        //     }
        //     ++cnt;
        // }

        // return number % mod;

        // ref
        long long number = 1;
        --k;
        while (k > 0) {
            long long steps = 0, first = number, last = number + 1;

            // Count the steps between number and number+1 in lexicographical order
            while (first <= n) {
                steps += min(n + 1LL, last) - first;
                first *= 10;
                last *= 10;
            }

            if (steps <= k) {
                // If the k-th number is not in the subtree of `number`, move to the next sibling
                number++;
                k -= steps;
            } else {
                // If the k-th number is within the subtree of `number`, go down one level
                number *= 10;
                k--;
            }
        }

        return number;
    }
};
