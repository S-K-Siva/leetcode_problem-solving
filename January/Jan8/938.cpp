#include<bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
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
    int total;
    Solution(){
        total = 0;
    }
    void helper(TreeNode *root, int low, int high){
        if(root == NULL) return;
        if(root->val >= low && root->val <= high){
            total += root->val;
        }
        helper(root->left,low,high);
        helper(root->right,low,high);
        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        helper(root,low,high);
        return total;
    }
};