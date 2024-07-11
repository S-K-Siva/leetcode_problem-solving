#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int> &s, TreeNode *p, TreeNode* q){
        if(!p || !q){
            if((!p && q) || (p && !q) ){
                s.push_back(-1);
            }
            return;
        }
        if(p->val == q->val){
            helper(s,p->left,q->left);
            helper(s,p->right,q->right);
        }else{
            s.push_back(-1);
            return;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> res;
        helper(res,p,q);
        for(auto it : res){
            cout << it << " ";
        }cout << endl;
        if(res.size()) return false;
        return true;
    }
};