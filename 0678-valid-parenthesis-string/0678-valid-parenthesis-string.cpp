class Solution {
public:
    int dp[101][101][101];
    bool rec(string & s, int i,int open,int closed){
        if(i == s.length())return open == closed;
        if(closed > open)return false;
        if(dp[i][open][closed]!=-1)return dp[i][open][closed];
        bool ans = false;
        if(s[i] == '('){
            ans = rec(s,i+1,open+1,closed);
        }
        else  if(s[i] == ')'){
            ans = rec(s,i+1,open,closed+1);
        }
        else{
            ans |= rec(s,i+1,open+1,closed);
            ans |= rec(s,i+1,open,closed+1);
            ans |= rec(s,i+1,open,closed);
        }
        return dp[i][open][closed] = ans;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return rec(s,0,0,0);
    }
};