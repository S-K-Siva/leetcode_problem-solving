#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int onesCnt = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size(); 
        int zeros = 0;
        int result = INT_MAX;

        // circular array...
        nums.insert(nums.end(), nums.begin(), nums.end());

        // initialize window size
        for (int i = 0; i < onesCnt; i++) {
            if (nums[i] == 0) zeros++;
        }

        result = min(result, zeros); // Update the result with the initial count of zeros

        // Slide the window across the circular array
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] == 0) zeros--; // Remove the leftmost element of the previous window
            if (nums[i + onesCnt - 1] == 0) zeros++; // Add the new rightmost element of the current window
            result = min(result, zeros); // Update the result
        }

        return result;
    }
};
