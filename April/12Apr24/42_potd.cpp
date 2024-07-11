#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size()),right(height.size());
        int result = 0;
        left[0] = height[0];
        right[height.size()-1] = height[height.size()-1];

        for(int i = 1;i<height.size();i++){
            left[i] = max(height[i],left[i-1]);
        }

        for(int i = height.size()-2;i>-1;i--){
            right[i] = max(height[i],right[i+1]);
        }

        for(int i = 1;i<height.size()-1;i++){
            result += min(left[i],right[i]) - height[i];
        }

        return result;
    }

};