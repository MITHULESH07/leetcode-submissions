class Solution {
public:
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,-1,0,1};

    int n,m;
    bool isValid (int i, int j){
        return (i>=0 && i < n && j >=0 && j<m);
    }
    void can_reach_ocean(vector<vector<int>>& heights,int i, int j,vector<vector<bool>>& ocean){
        ocean[i][j] = true;
        for(int k = 0; k < 4; k++){
            int di, dj ;
            di = dx[k] + i;
            dj = dy[k] + j;
            if(!isValid(di,dj))continue;
            if(heights[di][dj] >= heights[i][j] && !ocean[di][dj]){
                can_reach_ocean(heights,di,dj,ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
        for(int i = 0; i < n; i++){
            can_reach_ocean(heights,i,0,pacific);
            can_reach_ocean(heights,i,m-1,atlantic);
        }
        for(int j = 0; j < m; j++){
            can_reach_ocean(heights,0,j,pacific);
            can_reach_ocean(heights,n-1,j,atlantic);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};