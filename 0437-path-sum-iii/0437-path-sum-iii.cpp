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
    int target;
    void rec(TreeNode* root, vector<long long>& sums){
        if(!root)return;
        if(root->val == target){
            ans++;
        }
        for(int i = 0; i < sums.size();i++){
            sums[i] += root->val;
            if(sums[i] == target){
                ans++;
            }
        }
        sums.push_back(root->val);
        rec(root->left,sums);
        rec(root->right,sums);
        sums.pop_back();
        for(int i = 0; i < sums.size();i++){
            sums[i] -= root->val;
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        vector<long long>sums;
        rec(root,sums);
        return ans;
    }
};