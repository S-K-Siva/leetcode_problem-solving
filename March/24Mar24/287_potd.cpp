#include<bits/stdc++.h>
using namespace std;

static void* init = [] () {std::ios_base::sync_with_stdio(false); std::cout.tie(nullptr); std::cin.tie(nullptr); return nullptr;} ();
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it : nums){
            if(mp[it]) return it;
            else mp[it] = 1;
        }

        return -1;
    }
};