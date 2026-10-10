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
    int ans = INT_MIN;
    int diameter(TreeNode* root){
        if(!root)return 0;
        int dleft = diameter(root->left);
        int dright = diameter(root->right);
        int dia = dleft+dright+root->val;
        ans = max({ans,dia,root->val+dleft,root->val+dright});
        return max({root->val+dleft,root->val+dright,0});
    }
    int maxPathSum(TreeNode* root) {
        diameter(root);
        return ans;
    }
};