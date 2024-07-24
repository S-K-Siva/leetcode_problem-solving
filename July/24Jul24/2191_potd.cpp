#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<char, char> Map; // SC : O(m)
        int m = mapping.size();
        int n = nums.size();
        
        // Step 1: Create the mapping dictionary
        for (int i = 0; i < m; i++) {
            char ch = '0' + i;
            char chTo = '0' + mapping[i];
            Map[ch] = chTo;
        }
        
        // Step 2: Convert each number in nums based on the mapping
        vector<pair<int, int>> lst; 
        // SC : O(n)

        // TC : O(n * len(n))
        for (int num : nums) {
            string stringNum = to_string(num);
            string resultNum = "";
            for (char digit : stringNum) {
                resultNum += Map[digit];
            }
            lst.push_back({stoi(resultNum), num});
        }
        
        // Step 3: Sort the list based on the first element of the pair (mapped value)
        // TC : O(n*log(n))
        sort(lst.begin(), lst.end(), [&](pair<int, int>& a, pair<int, int>& b){
            return a.first < b.first;
        });
        
        // Step 4: Extract the original numbers in sorted order
        vector<int> result;
        // TC : O(n)
        for (auto& pair : lst) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};