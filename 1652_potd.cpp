class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k == 0){
            return vector<int>(n,0);
        }


        int start = (k > 0) ? 1 : n + k;
        int end = (k > 0) ? k : n - 1;

        int total = 0;

        for(int i = start;i<=end;i++){
            total += code[i%n];
        }

        vector<int> result;
        // sliding window..
        for(int i = 0;i<n;i++){
            result.push_back(total);
            total -= code[start % n];
            start++;
            end++;
            total += code[end % n];
        }

        return result;
    }
};
