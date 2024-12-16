class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> own;
        for(int i = 0;i<nums.size();i++){
            own.push({nums[i],i});
        }

        while(k--){
            pair<int,int> top = own.top();
            own.pop();
            own.push({top.first*multiplier,top.second});
        }

        vector<pair<int,int>> result;
        while(!own.empty()){
            result.push_back(own.top());
            own.pop();
        }

        sort(result.begin(),result.end(),[&](pair<int,int> niki, pair<int,int> md){
            return niki.second < md.second;
        });

        vector<int> res;
        for(auto it : result){
            res.push_back(it.first);
        }
        return res;
    }
};
