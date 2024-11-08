class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int total = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            total ^= nums[i];
        }
        
        int maxi = (1 << maximumBit) - 1;


        vector<int> result;

        for(int i = n-1;i>=0;i--){
            result.push_back(total ^ maxi);
            total ^= nums[i];
        }

        return result;
    }
};
