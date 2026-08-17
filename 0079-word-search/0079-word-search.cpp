class Solution {
public:
    int n,m;
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,-1,0,1};
    bool isSafe(int i,int j){
        return !(i<0 ||j<0||i>=n||j>=m);
    }
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& vis,string &word,int x,int y,int i){
        vis[x][y] = true;
        for(int k = 0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(i+1==word.size())return true;
            if(isSafe(nx,ny) && !vis[nx][ny] && word[i+1]==board[nx][ny] ){
                if(dfs(board,vis,word,nx,ny,i+1))return true;
                vis[nx][ny]=false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(word[0]==board[i][j]){
                    vector<vector<bool>>vis(n,vector<bool>(m,false));
                    if(dfs(board,vis,word,i,j,0)){return true;}
                }
            }
        }
        return false;
    }
};