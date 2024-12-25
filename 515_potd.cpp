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
    vector<int> largestValues(TreeNode* root) {

        vector<int> sc;
        if(!root) return sc;
        queue<pair<TreeNode*,int>> np;
        np.push({root,1});
        map<int,int> md;
        while(!np.empty()){
            
            pair<TreeNode *,int> current;
            current = np.front();
            int level = current.second;
            TreeNode *node = current.first;
            np.pop();
            if(md.find(level) == md.end()){
                md[level] = node->val;
            }else{
                md[level] = max(md[level], node->val);
            }
            if(node->left) np.push({node->left,level+1});
            if(node->right) np.push({node->right,level+1});

        }
        
        for(auto it : md){
            sc.push_back(it.second);
        }
        
        return sc;

    }
};
