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


    bool helper(TreeNode* p,TreeNode* q){
        if(p == NULL && q == NULL){
            return false;
        }
        if(p && q){
            if(p->val == q->val){
                if(helper(p->left,q->left) == true){
                    return true;
                }
                if(helper(p->right,q->right) == true){
                    return true;
                }
            }else{
                return true;
            }
        }else{
            return true;
        }
        return false;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(helper(p,q)){
            return false;
        }
        return true;
    }
};