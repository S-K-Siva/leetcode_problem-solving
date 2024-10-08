class Solution {
public:
    int minSwaps(string s) {
        stack<char> m;
        for(int i = 0;i<s.size();i++){
            if(m.empty()){
                m.push(s[i]);
            }else if(!m.empty() && (s[i] == ']' && m.top() == '[')){
                m.pop();
            }else{
                m.push(s[i]);
            }
        }
        return ((m.size()/2)+1)/2;
    }
};
