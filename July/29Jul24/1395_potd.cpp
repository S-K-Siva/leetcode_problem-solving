#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // TLE

    // void solve(vector<vector<int>>& res, vector<int>& current, vector<int>& rating, int index, int n) {
    //     if(current.size() == 3) {
    //         if(find(res.begin(), res.end(), current) == res.end()) {
    //             res.push_back(current);
    //         }
    //         return;
    //     }
    //     if(index == n) return;

    //     for(int i = index; i < n; i++) {
    //         if(current.empty() || current.back() < rating[i]) {
    //             current.push_back(rating[i]);
    //             solve(res, current, rating, i + 1, n);
    //             current.pop_back();
    //         }
    //     }
    // }

    // void solve2(vector<vector<int>>& res, vector<int>& current, vector<int>& rating, int index, int n) {
    //     if(current.size() == 3) {
    //         if(find(res.begin(), res.end(), current) == res.end()) {
    //             res.push_back(current);
    //         }
    //         return;
    //     }
    //     if(index == n) return;

    //     for(int i = index; i < n; i++) {
    //         if(current.empty() || current.back() > rating[i]) {
    //             current.push_back(rating[i]);
    //             solve2(res, current, rating, i + 1, n);
    //             current.pop_back();
    //         }
    //     }
    // }

    // int numTeams(vector<int>& rating) {
    //     vector<vector<int>> increasingResult;
    //     vector<vector<int>> decreasingResult;
    //     vector<int> current;
        
    //     int n = rating.size();
        
    //     // Find increasing subsequences
    //     solve(increasingResult, current, rating, 0, n);
        
    //     // Find decreasing subsequences
    //     solve2(decreasingResult, current, rating, 0, n);

    //     return increasingResult.size() + decreasingResult.size();
    // }


    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;

        // Count increasing subsequences
        for (int j = 1; j < n - 1; ++j) {
            int leftLess = 0, rightGreater = 0;
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    ++leftLess;
                }
            }
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] > rating[j]) {
                    ++rightGreater;
                }
            }
            count += leftLess * rightGreater;
        }

        // Count decreasing subsequences
        for (int j = 1; j < n - 1; ++j) {
            int leftGreater = 0, rightLess = 0;
            for (int i = 0; i < j; ++i) {
                if (rating[i] > rating[j]) {
                    ++leftGreater;
                }
            }
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) {
                    ++rightLess;
                }
            }
            count += leftGreater * rightLess;
        }

        return count;
    }
};
