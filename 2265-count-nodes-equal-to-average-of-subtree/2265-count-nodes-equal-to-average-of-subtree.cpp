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
    int ans = 0;
    pair<int,int> checkAvg(TreeNode* root){
        if(!root)return {0,0};
        auto left_subtree = checkAvg(root->left);
        auto right_subtree = checkAvg(root->right);
        int left_sum = left_subtree.first;
        int left_nodes = left_subtree.second;
        int right_sum = right_subtree.first;
        int right_nodes = right_subtree.second;
        int total_sum = left_sum + right_sum + root->val;
        int total_nodes = left_nodes + right_nodes + 1;
        int avg = (total_sum / total_nodes);
        if(avg == root->val){
            ans++;
        } 
        return {total_sum , total_nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        checkAvg(root);
        return ans;
    }
};