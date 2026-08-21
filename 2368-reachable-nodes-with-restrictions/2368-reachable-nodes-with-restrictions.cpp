class Solution {
public:
    int ans =0;
    void rec(vector<vector<int>>& adj,int root,vector<bool>&res){
        ans++;
        for(int a:adj[root]){
            if(!res[a]){
                res[a]=true;
                rec(adj,a,res);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>adj(n);
        vector<bool>res(n);
        for(vector<int> e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int r :restricted)res[r]=true;
        res[0]=true;
        rec(adj,0,res);
        return ans;
    }
};