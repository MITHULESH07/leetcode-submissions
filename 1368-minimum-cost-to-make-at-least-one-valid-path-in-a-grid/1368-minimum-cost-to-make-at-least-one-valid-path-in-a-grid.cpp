class Solution {
public:
    vector<int>dx = {0,0,1,-1};
    vector<int>dy = {1,-1,0,0};
    using PIII = pair<int,pair<int,int>>;
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>cost(m,vector<int>(n ,INT_MAX));
        priority_queue<PIII,vector<PIII>,greater<PIII>>pq;
        pq.push({0,{0,0}});
        cost[0][0] = 0;
        while(!pq.empty()){
            int c = pq.top().first;
            auto [x,y] = pq.top().second;
            pq.pop();
            for(int i = 0;i < 4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0||nx >=m||ny>=n)continue;
                int newCost = c + (grid[x][y] != i+1);
                if(newCost < cost[nx][ny]){
                    cost[nx][ny] = newCost;
                    pq.push({newCost,{nx,ny}});
                }
            }
        }
        return cost[m-1][n-1];
    }
};