class Solution {
public:
    using PIII =pair<int,int>;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        queue<PIII>q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || ny<0 || nx>=n||ny>=m||ans[nx][ny]!=INT_MAX)continue;
                ans[nx][ny] = ans[x][y]+1;
                q.push({nx,ny});
            }
        }
        return ans;
    }
};