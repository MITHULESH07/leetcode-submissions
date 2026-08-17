class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<int>&clr,int i){
        bool ans = true;
        for(int j:adj[i]){
            if(clr[j]==-1){
                clr[j] = !clr[i];
                ans = ans && dfs(adj,clr,j);
            }
            else if(clr[i]==clr[j])return false;
        }
        return ans;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>clr(n+1,-1);
        vector<vector<int>>adj(n+1);
        for(int i = 0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i =1;i<=n;i++){
            if(clr[i]==-1){
                clr[i]=1;
                if(!dfs(adj,clr,i))return false;
            }
        }
        return true;
    }
};