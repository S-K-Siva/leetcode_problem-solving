class Solution {
public:
    string compressedString(string word) {
        string res = "";

        int cnt = 1;
        int n = word.size();
        char prev = word[0];
        for(int i = 1;i<n;i++){
            if(word[i] == prev && cnt < 9){
                cnt++;
            }else{
                res += to_string(cnt);
                res += prev;
                prev = word[i];
                cnt = 1;
            }
        }
        res += to_string(cnt);
        res += prev;
        return res;
    }
};
