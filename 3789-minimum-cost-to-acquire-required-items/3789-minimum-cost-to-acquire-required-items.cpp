class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1==0 && need2==0)return 0;
        int n = min(need1,need2);
        long long cost = min((1ll*(cost1+cost2)*n),(1ll*costBoth*n));
        need1 -= n;
        need2 -= n;
        return cost + min(1ll*cost1*need1+1ll*cost2*need2,1ll*max(need1,need2)*costBoth); 
    }
};