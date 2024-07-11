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
    void helper(vector<int>&result, TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL){
            result.push_back(root->val);
            return;
        }
        if(root->left)
            helper(result,root->left);
        if(root->right)
            helper(result,root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1,arr2;
        helper(arr1,root1);
        helper(arr2,root2);
        return arr1 == arr2;
    }
};