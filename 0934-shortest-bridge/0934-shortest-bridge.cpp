class Solution {
public:
    int n;
    using PII = pair<int,int>;
    using PIII = pair<int,PII>;
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,-1,0,1};
    queue<PIII>q;
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,int i,int j){
        if(i<0||j<0||i>=n||j>=n||vis[i][j])return;
        vis[i][j]=true;
        if(grid[i][j]==0){
            cout<<"0";
            q.push({1,{i,j}});
            return;
        }
        for(int k = 0;k<4;k++){
            int ni = i+dx[k]; 
            int nj = j+dy[k];
            dfs(grid,vis,ni,nj);
            } 
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        bool state = false;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,vis,i,j);
                    state = true;
                    break;
                }
            }
            if(state)break;
        }
        while(!q.empty()){
            int d = q.front().first;
            auto [x,y] = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0 || ny<0||nx>=n||ny>=n)continue;
                if(!vis[nx][ny]){
                    if(grid[nx][ny]==1){
                        return d;
                    }
                    vis[nx][ny]=true;
                    q.push({d+1,{nx,ny}});
                }
            }
        }
        return 0;
    }
};