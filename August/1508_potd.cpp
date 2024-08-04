#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long int mod = 1e9 + 7;
        vector<int> subArraySums;

        // Insert individual elements
        subArraySums.insert(subArraySums.end(), nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            long long int subArrayTotal = nums[i]; // Initialize with the first element
            for (int j = i + 1; j < n; ++j) {
                subArrayTotal += nums[j];
                int insertVal = subArrayTotal % mod;
                subArraySums.push_back(insertVal);
            }
        }

        // Sort the sums
        sort(subArraySums.begin(), subArraySums.end());

        // Accumulate the sums from left to right
        long long int res = accumulate(subArraySums.begin() + left - 1, subArraySums.begin() + right, 0LL);

        return res % mod;
    }
};
