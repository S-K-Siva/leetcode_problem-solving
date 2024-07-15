#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> children;

        for (auto nums : descriptions) {
            int parent = nums[0];
            int child = nums[1];
            int isLeft = nums[2];

            if (mpp.find(parent) == mpp.end()) {
                mpp[parent] = new TreeNode(parent);
            }
            if (mpp.find(child) == mpp.end()) {
                mpp[child] = new TreeNode(child);
            }

            if (isLeft == 1) {
                mpp[parent]->left = mpp[child];
            } else {
                mpp[parent]->right = mpp[child];
            }

            children.insert(child);
        }

        for (auto nums : descriptions) {
            if (children.find(nums[0]) == children.end()) {
                return mpp[nums[0]];
            }
        }

        return nullptr;
    }
};