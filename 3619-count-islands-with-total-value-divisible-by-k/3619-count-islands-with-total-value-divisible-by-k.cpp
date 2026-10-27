class Solution {
public:
    int n,m;
    vector<int> dx = {-1,0,1,0}, dy= {0,-1,0,1};
    long long dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j){
        if(i == n || j == m || i < 0 || j < 0 || grid[i][j]==0 || vis[i][j])return 0;
        vis[i][j] = true;
        long long pathSum = grid[i][j];
        for(int k = 0; k < 4;k++){
            int nx = i + dx[k], ny = j + dy[k];
            pathSum += dfs(grid,vis,nx,ny);
        }
        return pathSum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(grid[i][j]>0 && !vis[i][j]){
                    long long sum = dfs(grid,vis,i,j);
                    ans += (sum%k == 0);
                }
            }
        }
        return ans;
    }
};