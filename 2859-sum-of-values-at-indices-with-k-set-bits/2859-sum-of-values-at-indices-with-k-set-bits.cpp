class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n,0);
        int ans= 0;
        if(dp[0]==k)ans+=(nums[0]);
        for(int i = 1;i < n;i++){
            dp[i] = dp[i&(i-1)]+1;
            if(dp[i]==k){
                ans += nums[i]; 
            }
        }
        return ans;
    }
};