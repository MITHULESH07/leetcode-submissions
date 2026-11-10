class Solution {
public:
    int dp[100005];
    int n;
    int rec(vector<int>& costs, int i){
        if(i > n)return INT_MAX;
        if(i == n)return 0;
        if(dp[i]!=-1)return dp[i];
        int step1 = rec(costs,i+1);
        int step2 = rec(costs,i+2);
        int step3 = rec(costs,i+3);
        step1 = (step1==INT_MAX) ? INT_MAX : (step1 + costs[i]+1); 
        step2 = (step2==INT_MAX) ? INT_MAX : (step2 + costs[i+1]+4); 
        step3 = (step3==INT_MAX) ? INT_MAX : (step3 + costs[i+2]+9);
        return dp[i] = min(step1,min(step2,step3)); 
    }
    int climbStairs(int n, vector<int>& costs) {
        this->n = n;
        memset(dp,-1,sizeof(dp));
        return rec(costs,0);
    }
};