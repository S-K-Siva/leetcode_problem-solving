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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* > q;
        vector<TreeNode* > arr;
        q.push(root);
        while(!q.empty()){
            arr.push_back(q.front());
            queue<TreeNode*> subqueue;
            while(!q.empty()){
                TreeNode* value;
                value = q.front();
                if(value->left != NULL)
                    subqueue.push(value->left);
                if(value->right != NULL)
                    subqueue.push(value->right);
                
                q.pop();
            }

            q = subqueue;
        }
        return arr[arr.size()-1]->val;

    }
};