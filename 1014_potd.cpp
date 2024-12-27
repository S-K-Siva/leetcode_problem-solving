class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxi = INT_MIN;
        int prev = values[0];
        for(int i = 1;i<n;i++){
            maxi = max(maxi, prev + values[i] - i);
            prev = max(prev, values[i] + i);
        }
        return maxi;
    }
};
