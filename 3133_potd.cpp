class Solution {
public:
    long long minEnd(int n, int x) {
        long long int res = x;
        long long int pos = 1;
        long long int N = n-1;

        while(N){
            if((x & pos) == 0){
                res |= (N & 1) * pos;
                N>>=1;
            }
            pos <<= 1;
        }

        return res * 1LL;
    }
};
