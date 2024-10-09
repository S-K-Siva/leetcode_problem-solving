class Solution {
public:
    int minAddToMakeValid(string s) {
        //with space
        // stack<char> m;
        // for(int i = 0;i<s.size();i++){
        //     if(m.empty()){
        //         m.push(s[i]);
        //     }else{
        //         if(s[i] == ')' && !m.empty() && m.top() == '('){
        //             m.pop();
        //         }else{
        //             m.push(s[i]);
        //         }
        //     }
        // }

        // return m.size();


        //without space
        string m = "";
        for(int i = 0;i<s.size();i++){
            if(m.empty()){
                m+=s[i];
            }else{
                if(m.back() == '(' && s[i] == ')'){
                    m.pop_back();
                }else{
                    m.push_back(s[i]);
                }
            }
        }

        return m.size();
    }
};
