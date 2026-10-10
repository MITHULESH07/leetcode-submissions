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
    unordered_map<TreeNode*,int> dp;
    int rec(TreeNode* root){
        if(!root)return 0;
        if(dp.find(root)!=dp.end())return dp[root];
        int take = root->val;
        int skip = 0;
        if(root->left){
            take += rec(root->left->left)+rec(root->left->right);
        }
        if(root->right){
            take += rec(root->right->left)+rec(root->right->right);
        }
        skip += rec(root->left)+rec(root->right);
        return dp[root] = max(take,skip);
    }
    int rob(TreeNode* root) {
        return rec(root);
    }
};