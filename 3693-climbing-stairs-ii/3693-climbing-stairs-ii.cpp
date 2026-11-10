class Solution {
public:
    vector<int>dp;
    int n;
    int rec(vector<int>& costs, int i){
        if(i > n)return INT_MAX;
        if(i == n)return costs[i-1];
        if(dp[i]!=-1)return dp[i];
        int step1 = rec(costs,i+1);
        int step2 = rec(costs,i+2);
        int step3 = rec(costs,i+3);
        step1 = (step1==INT_MAX) ? INT_MAX : (step1+1); 
        step2 = (step2==INT_MAX) ? INT_MAX : (step2+4); 
        step3 = (step3==INT_MAX) ? INT_MAX : (step3+9);
        int curr = min(step1,min(step2,step3));
        curr += (i>0 && curr!=INT_MAX) ? costs[i-1] : 0;  
        return dp[i] = curr; 
    }
    int climbStairs(int n, vector<int>& costs) {
        this->n = n;
        dp.resize(n+1,-1);
        return rec(costs,0);
    }
};