class Solution {
public:
    int n,m;
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,-1,0,1};
    bool dfs(vector<vector<char>>&grid,vector<vector<bool>>&vis,int x,int y,int px,int py,char c){
        vis[x][y] = true;
        bool ans = false;
        for(int k = 0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx<0 ||ny<0||nx>=n||ny>=m||(nx==px && ny==py))continue;
            if(c == grid[nx][ny]){
                if(vis[nx][ny])return true;
                ans = ans || dfs(grid,vis,nx,ny,x,y,c);
            }
        }
        return ans;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(); 
        m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j])
                if(dfs(grid,vis,i,j,-1,-1,grid[i][j]))return true;
            }
        }
        return false;
    }
};