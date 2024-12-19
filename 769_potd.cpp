class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int maxi = 0;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            maxi = max(maxi,arr[i]);
            if(maxi == i){
                ++res;
            }
        }
        return res;
    }
};
