#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    multiset<int> vals;  // Using multiset to allow duplicate values
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        this->vals.insert(nums.begin(), nums.end());
        this->K = k;
    }
    
    int add(int val) {
        this->vals.insert(val);
        auto it = this->vals.rbegin();  // reverse iterator to get largest elements
        
        // Move the iterator to the k-th largest element
        for (int i = 1; i < this->K; ++i) {
            ++it;
        }
        
        return *it;  // return the k-th largest element
    }
};