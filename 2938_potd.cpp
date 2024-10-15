class Solution {
public:
    long long minimumSteps(string s) {
        long long white = 0;
        long long hs = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '1'){
                white++;
            }else{
                hs += white;
            }
        }
        return hs;
    }
};
