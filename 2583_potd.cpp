/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> hs;


        queue<TreeNode*> que;
        que.push(root);


        while(!que.empty()){
            long long sum = 0;
            queue<TreeNode*> temp;
            while(!que.empty()){
                TreeNode *current;
                current = que.front();
                sum += current->val;

                if(current->left)
                    temp.push(current->left);
                if(current->right)
                    temp.push(current->right);

                que.pop();
            }
            hs.push(sum);
            que = temp;
        }
        if(k > hs.size()) return -1LL;
        while(k != 1){
            hs.pop();
            k--;
        }
        if(hs.empty()) return -1LL;
        return hs.top();
    }
};
