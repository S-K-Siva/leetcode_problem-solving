class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxWidthRamp(vector<int>& nums) {
        // TLE (95/101)
        // set<pair<int,int>> ss;

        // for(int i = 0;i<nums.size();i++){
        //     ss.insert({nums[i],i});
        // }

        // vector<pair<int,int>> vals(ss.begin(),ss.end());
        // int n = vals.size();
        // int maxWidth = 0;
        // for(int i = 0;i<n;i++){
        //     for(int j = i+1;j<n;j++){
        //         if(vals[i].second < vals[j].second){
        //             maxWidth = max(maxWidth, vals[j].second-vals[i].second);
        //         }
        //     }
        // }
        // return maxWidth;


        // monotonic stack
        stack<int> decreasingIndex;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(decreasingIndex.empty() || nums[decreasingIndex.top()] >= nums[i]){
                decreasingIndex.push(i);
            }
        }


        int maxWidth = 0;
        for(int j = n-1;j>-1;j--){
            while(!decreasingIndex.empty() && nums[decreasingIndex.top()] <= nums[j]){
                maxWidth = max(maxWidth,j - decreasingIndex.top());
                decreasingIndex.pop();
            }
        }
        return maxWidth;
        
    }
};
