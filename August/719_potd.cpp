#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = 0, high = nums[n-1] - nums[0];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0, left = 0;

            // Count how many pairs have distance <= mid
            for (int right = 0; right < n; ++right) {
                while (nums[right] - nums[left] > mid) {
                    ++left;
                }
                count += right - left;
            }

            if (count >= k) {
                high = mid; // We need a smaller or equal distance
            } else {
                low = mid + 1; // We need a larger distance
            }
        }

        return low;
    }
};
