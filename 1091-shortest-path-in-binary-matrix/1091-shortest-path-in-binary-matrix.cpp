class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1 && grid[0][0]==0)return 1;
        if(grid[0][0]==1 ||grid[n-1][n-1]){return -1;}
        queue<pair<int,pair<int,int>>>q;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[0][0] = true;
        q.push({1,{0,0}});
        int dx[] = {-1,0,1,0,-1,-1,1,1};
        int dy[] = {0,-1,0,1,-1,1,-1,1};
        while(!q.empty()){
            int d = q.front().first;
            auto [x,y] = q.front().second;
            q.pop();
            for(int i = 0;i<8;i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if(nx<0||ny<0||nx>=n||ny>=n||grid[nx][ny]==1||vis[nx][ny])continue;
                if(nx==n-1 && ny==n-1)return d+1;
                vis[nx][ny] = true;
                q.push({d+1,{nx,ny}});
            }
        }
        return -1;
    }
};