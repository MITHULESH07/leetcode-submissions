class Solution {
public:
    int n;
    int mod = 1e9+7;
    string s;
    int dp[2005];
    int nextpos[2005];
    int rec(int i){
        if(i==n)return 1;
        if(dp[i]!=-1)return dp[i];
        int ans = 2 * rec(i+1);
        if(nextpos[i]!=-1){
            ans -= rec(nextpos[i]+1);
        }
        return dp[i] = (ans % mod + mod) % mod;
    }
    int distinctSubseqII(string s) {
        n = s.length();
        this->s = s;
        memset(dp,-1,sizeof(dp));
        memset(nextpos,-1,sizeof(nextpos));
        vector<int>last(26,-1);
        for(int i = n-1; i >=0 ;i--){
            nextpos[i] = last[s[i]-'a'];
            last[s[i]-'a'] = i;
        }
        int ans = (rec(0) % mod - 1 + mod)% mod;
        return ans;
    }
};