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
    using pl = pair<int,int>;
    int ans = 0;
    pl dfs(TreeNode*root){
        pl ret;
        ret.first++;
        ret.second+=root->val;
        if(root->left!=nullptr){
            auto X = dfs(root->left);
            ret.first+=X.first;
            ret.second+=X.second;
        }
        if(root->right!=nullptr){
            auto X = dfs(root->right);
            ret.first+=X.first;
            ret.second+=X.second;
        }
        if(root->val == ret.second/ret.first)++ans;
        return ret;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
