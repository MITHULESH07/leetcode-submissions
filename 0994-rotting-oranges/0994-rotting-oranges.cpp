class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                q.push({0,{i,j}});
            }
        }
        vector<int>dx = {-1,0,1,0};
        vector<int>dy = {0,-1,0,1};
        while(!q.empty()){
            int t = q.front().first;
            auto [x,y] = q.front().second;
            q.pop();
            ans = max(ans,t);
            for(int k = 0;k<4;k++){
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(nx<0||ny<0||nx>=n||ny>=m)continue;
                if(grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    q.push({t+1,{nx,ny}});
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return ans;
    }
};