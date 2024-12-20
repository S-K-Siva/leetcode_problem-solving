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

    void getNodes(TreeNode* root, vector<int>& vec){
        if(!root) return;

        queue<TreeNode*> que;
        que.push(root);
        int index = 0;
        
        while(!que.empty()){
            vector<int> row;
            queue<TreeNode*> temp;
            while(!que.empty()){
                TreeNode* current = que.front();
                que.pop();
                row.push_back(current->val);
                if(current->left) temp.push(current->left);
                if(current->right) temp.push(current->right);
            }
            if(index % 2 == 1){
                reverse(row.begin(), row.end());
            }
            ++index;
            que = temp;
            vec.insert(vec.end(), row.begin(), row.end());
        }
    }


    void feedData(TreeNode*& root, vector<int> data){
        int index = 0;
        queue<TreeNode*> que;
        que.push(root);
        int rowIndex = 0;
        while(!que.empty()){
            queue<TreeNode*> temp;
            while(!que.empty()){
                TreeNode* current;
                current = que.front();
                que.pop();
                current->val = data[index++];
                if(current->left) temp.push(current->left);
                if(current->right) temp.push(current->right);
               
            }
            que = temp;
            ++rowIndex;
        }

    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> allData;
        getNodes(root, allData);
        feedData(root, allData);
        return root;
    }
};
