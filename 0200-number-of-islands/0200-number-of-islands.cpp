class Solution {
public:
    int n,m;
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>&vis,int i,int j){
        if(i<0 ||j<0 ||i>=n||j>=m||grid[i][j]=='0'||vis[i][j])return;
        vis[i][j]=true;
        dfs(grid,vis,i+1,j);
        dfs(grid,vis,i-1,j);
        dfs(grid,vis,i,j+1);
        dfs(grid,vis,i,j-1);
    } 
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int island = 0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    island++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return island;
    }
};