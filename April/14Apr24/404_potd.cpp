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

    int helper(char side,TreeNode* root){
        
        if(side == 'L' && root){
            if(root->left == NULL && root->right == NULL){
                return root->val;
            }
        }else if(side == 'R' && root){
            if(root->left == NULL && root->right == NULL){
                return 0;
            }
        }
        
        int left = 0,right = 0;
        if(root && root->left != NULL)
            left = helper('L',root->left);
        if(root && root->right != NULL)
            right = helper('R',root->right);
        return left + right;

    }
    int sumOfLeftLeaves(TreeNode* root) {
        return helper('-',root);
    }
};