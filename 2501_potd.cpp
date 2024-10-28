class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<long long int,int> mpp;
        for(auto it : nums){
            ++mpp[it];
        }
        int maxCnt = 0;
        int cnt = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            cnt = 1;
            long long int val = nums[i];
            while(mpp[(long long int) val*val]){
                cnt++;
                val = val * val;
            }
            maxCnt = max(maxCnt, cnt);
            cnt = 0;
        }
        if(maxCnt == 1) return -1;
        return maxCnt;
    }
};
