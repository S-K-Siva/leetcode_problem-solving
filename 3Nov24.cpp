class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i] == goal[0]){
                string half1,half2;
                half1 = s.substr(i);
                half2 = s.substr(0,i);
                if(half1 + half2 == goal) return true;
            }
        }
        return false;
    }
};
