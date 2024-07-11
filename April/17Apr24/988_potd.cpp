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

    void helper(vector<string>& res,TreeNode* root,string current){
        if(root->left == NULL && root->right == NULL){
            res.push_back(current);
            return;
        }
        if(root->left){
            char next = 'a' + root->left->val;
            string nee = current + next;
            helper(res,root->left,nee);
        }
        if(root->right){
            char next = 'a' + root->right->val;
            string nee = current + next;
            helper(res,root->right,nee);
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        vector<string> result;
        string res = "";
        char m = 'a' + root->val;
        helper(result,root,res + m);

        for(int i = 0;i<result.size();i++)
        {
            string res = result[i];
            reverse(res.begin(),res.end());
            result[i] = res;
        }
        sort(result.begin(),result.end());
        return result[0];
    }
};