class Solution {
public:
    int arrangeCoins(int n) {
        int N = n;
        int res = 0;
        int length = 1;
        while(true){
            if(N-length < 0) break;
            if(N - length >= 0) res++;
            N-=length;
            length++;
        }
      
        return res;
    }
};