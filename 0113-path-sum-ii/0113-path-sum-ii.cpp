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
    vector<vector<int>>ans;
    int target;
    void rec(TreeNode* root,vector<int>& path,int sum){
        path.push_back(root->val);
        sum+=root->val;
        if(!root->left && !root->right){
            if(sum==target)
                ans.push_back(path);
            path.pop_back();
            return;
        }
        if(root->left)
        rec(root->left,path,sum);
        if(root->right)
        rec(root->right,path,sum);
        path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)return {};
        target=targetSum;
        vector<int>path;
        rec(root,path,0);
        return ans;
    }
};