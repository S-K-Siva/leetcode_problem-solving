class Solution {
public:

    void solve(int& result, vector<int> nums, int current,int expected, int index,int n){
        if(index > n) return;
        if(current == expected){
            result++;
        }
        for(int i = index;i<n;i++)
            solve(result,nums,current | nums[i],expected,i+1,n);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int result = 0;
        int expected = 0;
        for(auto it : nums){
            expected |= it;
        }
        int n = nums.size();
        solve(result, nums,0,expected,0,n);

        return result;
    }
};
