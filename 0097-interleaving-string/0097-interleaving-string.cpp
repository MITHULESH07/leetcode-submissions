class Solution {
public:
    int dp[101][101][201];
    string s1,s2,s3;
    int n,m;
    bool rec(int i,int j,int k){
        if(i == n && j == m)return true;
        if(s3[k]!=s1[i] && s3[k]!=s2[j])return false;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        bool ans = false;
        if(i<n && s1[i] == s3[k]){
            ans = ans || rec(i+1,j,k+1);
        }
        if(j<m && s2[j] == s3[k]){
            ans = ans || rec(i,j+1,k+1);
        }
        return dp[i][j][k] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        n = s1.length();
        m = s2.length();
        if(n+m != s3.length())return false;
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0);
    }
};