// 535 / 536 Testcase passed
// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         vector<bool> result;

//         for(auto it : queries){
//             int start = it[0];
//             int end = it[1];
//             bool pushed = false;
//             for(int i = start;i<end;i++){
//                 if((nums[i]%2 == 0 && nums[i+1]%2 == 1) || 
//                 (nums[i]%2 == 1 && nums[i+1]%2 == 0)){
//                     continue;
//                 }else{
//                     pushed = true;
//                     result.push_back(false);
//                     break;
//                 }
//             }
//             if(!pushed){
//                 result.push_back(true);
//             }
//         }
//         return result;
//     }
// };

// Optimized one
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        vector<int> dp(n,0);

        for(int i = 1;i<n;i++){
            if((nums[i]%2 == 0 && nums[i-1]%2 == 1) || 
            (nums[i]%2 == 1 && nums[i-1]%2 == 0)){
                dp[i] += dp[i-1] + 1;
            }
        }
        vector<bool> result;

        for(auto it : queries){
            int start = it[0];
            int end = it[1];

            result.push_back(end - start == dp[end] - dp[start]);

        }
        return result;
    }
};
