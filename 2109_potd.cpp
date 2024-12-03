class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int index = 0;
        int II = 0;
        string res = "";
        for(int i = 0;i<s.size();){
            
            if(II < spaces.size() && index == spaces[II]){
                ++II;
                res += " ";
            }else{
                res += s[i];
                i++;
                ++index;
            }
            
            
        }

        return res;
    }
};
