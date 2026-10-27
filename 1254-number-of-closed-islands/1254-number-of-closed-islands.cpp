class Solution {
public:
    int n,m;
    vector<int>dx ={-1,0,1,0}, dy = {0,-1,0,1};
    bool dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int x, int y){
        if(x == n || y == m || x < 0 || y < 0)return false;
        if(grid[x][y]==1 || vis[x][y])return true;
        vis[x][y] = true;
        bool ans = true;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            ans &= dfs(grid,vis,nx,ny);
        }
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    bool isIsland = dfs(grid,vis,i,j);
                    ans += isIsland;
                }
            }
        }
        return ans;
    }
};