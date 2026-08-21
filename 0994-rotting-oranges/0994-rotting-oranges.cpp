class Solution {
public:
    using PIII = pair<int,pair<int,int>>;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0,org =0;
        queue<PIII>q;
        int dx[] ={-1,0,1,0};
        int dy[]={0,-1,0,1}; 
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
                else if(grid[i][j]==1){
                    org++;
                }
            }
        }

        while(!q.empty()){
            int t = q.front().first; 
            auto [x,y] = q.front().second;
            q.pop(); 
            for(int i = 0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                ans = max(t,ans);
                if(nx<0 || ny<0||nx>=n||ny>=m)continue;
                if(grid[nx][ny]==1){
                    grid[nx][ny]=2;
                    org--;
                    q.push({t+1,{nx,ny}});
                }
            }
        }
        return org==0?ans:-1;
    }
};