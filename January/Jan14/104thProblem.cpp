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
    int helper(TreeNode* root){
        if(root == NULL) return 1;
        
        return max(1+helper(root->left),1+helper(root->right));
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int result = helper(root);
        return result-1;
    }
};