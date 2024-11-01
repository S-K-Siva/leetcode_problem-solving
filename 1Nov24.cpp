class Solution {
public:
    string makeFancyString(string s) {
        map<char,int> mpp;

        string m = "";

        for(int i = 0;i<s.size();i++){
            if(m.empty()){
                m += s[i];
                ++mpp[s[i]];
            }else{
                if(s[i] == m.back()){
                    if(mpp[s[i]] < 2){
                        m += s[i];
                        ++mpp[s[i]];
                    }
                }else{
                    mpp.erase(m.back());
                    m+=s[i];
                    ++mpp[s[i]];
                }
            }
        }
        return m;
    }
};
