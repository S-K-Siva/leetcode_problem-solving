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
    bool helper(TreeNode *root1, TreeNode *root2){
        if( root1 == NULL || root2 == NULL ){
            return root1 == root2;
        }
        if(root1->val != root2->val) return false;

        return helper(root1->left , root2->right) && helper(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
};