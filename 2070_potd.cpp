// 33/35 testcases
// class Solution {
// public:
//     vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
//         vector<int> res;
//         int q = queries.size();
//         int size = items.size();
//         for(int i = 0;i<q;i++){
//             int maxBeauty = 0;
//             for(auto it : items){
//                 if(it[0] <= queries[i]){
//                     maxBeauty = max(maxBeauty, it[1]);
//                 }
//             }
    
//             res.push_back(maxBeauty);
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> res;
        
        sort(items.begin(), items.end());

        vector<pair<int, int>> track;
        int maxBeauty = 0;
        
        for (auto item : items) {
            maxBeauty = max(maxBeauty, item[1]);
            if (track.empty() || track.back().first != item[0]) {
                track.push_back({item[0], maxBeauty});
            } else {
                track.back().second = maxBeauty;
            }
        }

        for (int query : queries) {
            auto it = upper_bound(track.begin(), track.end(), make_pair(query, INT_MAX));
            if (it == track.begin()) {
                res.push_back(0);
            } else {
                --it;
                res.push_back(it->second);
            }
        }
        
        return res;
    }
};
