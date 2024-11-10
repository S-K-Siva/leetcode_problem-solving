class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int total = 0;
        int i = 0, j = 0;
        int n = nums.size();
        int res = n + 1;
        vector<int> track(32, 0);

        while (i <= j && j < n) {
            total |= nums[j];

            // Update bit count for the number at position j
            for (int np = 0; np < 32; np++) {
                if (nums[j] & (1 << np)) {
                    ++track[31 - np];
                }
            }

            // Shrink the window from the left while `total` meets the condition
            while (i <= j && total >= k) {
                // Update result with the smallest subarray length
                res = min(res, j - i + 1);

                // Remove nums[i] from `total` by adjusting the bit count
                for (int ss = 0; ss < 32; ss++) {
                    if (nums[i] & (1 << ss)) {
                        --track[31 - ss];
                    }
                }
                i++;

                // Recalculate `total` based on updated bit counts
                int newTotal = 0;
                for (int bit = 31; bit >= 0; bit--) {
                    if (track[bit]) {
                        newTotal += (1 << (31 - bit));
                    }
                }
                total = newTotal;
            }
            j++;
        }
        return (res == n + 1) ? -1 : res;
    }
};
