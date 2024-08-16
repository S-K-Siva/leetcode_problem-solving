class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int d1 = arrays[0][0];
        int d2 = arrays[0][arrays[0].size()-1];
        int res = 0;
        for(int i = 1;i<arrays.size();i++){
            res = max(res, max(abs(arrays[i].back() - d1), abs(d2 - arrays[i][0])));
            d1 = min(d1,arrays[i][0]);
            d2 = max(d2,arrays[i][arrays[i].size()-1]);
        }

        return res;
    }
};