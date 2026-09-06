class Solution {
public:
    int n,m;
    string s,t;
    unsigned long long dp[1001][1001];
    int rec(int i,int j){
        if(i==n)return 1;
        if(j==m)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = 0;
        if(t[i] == s[j]){
            ans += rec(i+1,j+1);
        }
        ans += rec(i,j+1);
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        n = t.length();
        m = s.length();
        this->t = t;
        this->s = s;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};