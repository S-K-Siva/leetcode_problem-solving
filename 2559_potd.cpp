class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        map<char,int> vowels;
        vector<char> vs = {'a','e','i','o','u'};
        for(auto vowel : vs){
            ++vowels[vowel];
        }
        vector<int> prefixSum(n,0);
        prefixSum[0] = (vowels[words[0].front()] && vowels[words[0].back()]) ? 1 : 0;
        for(int i = 1;i<n;i++){
            string word = words[i];
            if(vowels[word.front()] && vowels[word.back()]){
                prefixSum[i] = prefixSum[i-1] + 1;
            }else{
                prefixSum[i] = prefixSum[i-1];
            }
        }
        vector<int> result;
        for(auto query : queries){
            int from = query.front();
            int back = query.back();

            int res = prefixSum[back];
            if(from > 0){
                res -= prefixSum[from-1];
            }
            result.push_back(res);
        }

        return result;
    }
};
