class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oColor = image[sr][sc];
        if(oColor == color)return image;
        int n = image.size(), m = image[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            image[x][y] = color;
            for(int i = 0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m||image[nx][ny]!=oColor)continue;
                q.push({nx,ny});
            }
        }
        return image;
    }
};