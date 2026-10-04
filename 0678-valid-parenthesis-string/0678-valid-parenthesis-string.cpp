class Solution {
public:
    int dp[101][201];
    bool rec(string & s, int i,int open){
        if(i == s.length())return open == 0;
        if(open < 0)return false;
        if(dp[i][open]!=-1)return dp[i][open];
        bool ans = false;
        if(s[i] == '('){
            ans = rec(s,i+1,open+1);
        }
        else  if(s[i] == ')'){
            ans = rec(s,i+1,open-1);
        }
        else{
            ans |= rec(s,i+1,open+1);
            ans |= rec(s,i+1,open-1);
            ans |= rec(s,i+1,open);
        }
        return dp[i][open] = ans;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return rec(s,0,0);
    }
};