class Solution {
public:
    using PII = pair<int,int>;
    using PIII = pair<int,PII>;
    int swimInWater(vector<vector<int>>& grid) {
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<PIII,vector<PIII>,greater<PIII>>q;
        q.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];
        while(!q.empty()){
            int maxi = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            for(int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || ny<0 ||nx>=n || ny>=m)continue;
                if(max(maxi,grid[nx][ny]) < dist[nx][ny]){
                    dist[nx][ny] = max(maxi,grid[nx][ny]);
                    q.push({dist[nx][ny],{nx,ny}});
                }
            }  
        }
        return dist[n-1][m-1];
    }
};