class Solution {
public:
    vector<int>digit;
    int size;
    int dp[20][2][2][2][1050];
    int rec(int i,bool started,bool rep,bool tight,int vis){
        if(i==size)return started && rep;
        if(dp[i][started][rep][tight][vis]!=-1)return dp[i][started][rep][tight][vis];
        int limit = tight ? digit[i] : 9;
        int ans = 0;
        for(int j = 0; j <= limit;j++){
            bool newTight = (tight && j==limit);
            bool newStart = (started || j!=0);
            bool newRep = rep;
            int newVis = vis;
            if(newStart){
                if(vis & 1<<j)newRep = true;
                newVis = (vis | 1<<j);
            }
            ans += rec(i+1,newStart,newRep,newTight,newVis); 
        }
        return dp[i][started][rep][tight][vis] = ans;

    }
    int numDupDigitsAtMostN(int n) {
        int m = n;
        while(m > 0){
            digit.push_back(m % 10);
            m /= 10;
        }
        reverse(digit.begin(),digit.end());
        size = digit.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,false,false,true,0);
    }
};