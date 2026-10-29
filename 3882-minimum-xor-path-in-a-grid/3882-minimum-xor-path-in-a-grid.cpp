class Solution {
public:
    vector<vector<vector<int>>>dp;
    int n,m;

    int rec(vector<vector<int>>& grid, int i,int j,int x){
        if(i==n || j ==m)return INT_MAX;
        x ^= grid[i][j];
        if(i==n-1 && j==m-1)return x;
        if(dp[i][j][x]!=-1)return dp[i][j][x];
        int down = rec(grid,i,j+1,x);
        int up = rec(grid,i+1,j,x);
        return dp[i][j][x] = min(up,down);
    }

    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(1025,-1)));
        return rec(grid,0,0,0);
    }
};