class Solution {
public:
    int n,m;
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,-1,0,1};
    bool check(int i,int j){
        return !(i<0 ||j<0||i>=n||j>=m);
    }
    bool dfs(vector<vector<char>>&board,string word,vector<vector<bool>>&vis,int i,int j,int k){
        if(k==word.size())return true;
        bool ans = false;
        for(int x = 0;x<4;x++){
            int ni = i+dx[x];
            int nj = j+dy[x];
        if(check(ni,nj)&& !vis[ni][nj] && board[ni][nj]==word[k]){
            vis[ni][nj] = true;
            ans  = ans || dfs(board,word,vis,ni,nj,k+1);
            vis[ni][nj]=false;
        }
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=true;
                    if(dfs(board,word,vis,i,j,1))return true;
                    vis[i][j]=false;
                }
            }
        }
        return false;
    }
};