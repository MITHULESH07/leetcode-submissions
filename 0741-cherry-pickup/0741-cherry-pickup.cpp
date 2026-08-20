class Solution {
public:
    int n;
    int dp[55][55][55];
    int rec(vector<vector<int>>& grid,int r1,int c1,int r2,int c2){
        if(r1>=n ||r2>=n||c1>=n||c2>=n||grid[r1][c1]==-1||grid[r2][c2]==-1)return -1e8;
        
        if(r1==n-1 && c1==n-1)
            return grid[r1][c1];
        
        if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];
        
        int cherry = grid[r1][c1];
        
        if(r1!=r2 || c1!=c2){
            cherry += grid[r2][c2];
        }
        int maxi  = max({
            rec(grid,r1+1,c1,r2+1,c2),
            rec(grid,r1+1,c1,r2,c2+1),
            rec(grid,r1,c1+1,r2+1,c2),
            rec(grid,r1,c1+1,r2,c2+1)
            });

        return dp[r1][c1][r2] = maxi + cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,rec(grid,0,0,0,0));
        
    }
};