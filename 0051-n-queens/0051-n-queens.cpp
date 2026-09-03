class Solution {
public:
    int n;
    vector<vector<string>>ans;
    bool isSafe(vector<string>&board,int i,int j){
        for(int x = 0; x<j; x++){
            if(board[i][x] == 'Q')return false;
        }
        for(int x = i-1, y = j-1; (x>=0 &&y>=0);x--,y--){
            if(board[x][y] == 'Q')return false;
        }
        for(int x = i+1, y = j-1; (x<n &&y>=0);x++,y--){
            if(board[x][y] == 'Q')return false;
        }
        return true;
    }
    void NQueens(vector<string>&board, int i){
        if(i == n){
            ans.push_back(board);
            return;
        }
        for(int j = 0;j<n;j++){
            if(isSafe(board,j,i)){
                board[j][i] = 'Q';
                NQueens(board,i+1);
                board[j][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       this->n = n;
       vector<string>board(n,"");
       for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            board[i].push_back('.');
        }
       }
       NQueens(board,0);
       return ans; 
    }
};