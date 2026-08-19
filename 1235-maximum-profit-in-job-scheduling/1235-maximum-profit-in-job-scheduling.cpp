class Solution {
public:
    using VVI = vector<vector<int>>;
    int n;
    int dp[100005];
    int lower(vector<vector<int>>&arr,int x){
        int l = 0,h = n-1;
        int ans= n;
        while(l<=h){
            int m = l+(h-l)/2;
            if(arr[m][0]>=x){
                h = m-1;
                ans = m;
            }
            else
                l = m+1;
        }
        return ans;
    }
    int rec(int i,VVI &arr){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int skip = rec(i+1,arr);
        int x = lower(arr,arr[i][1]);
        int take = arr[i][2]+rec(x,arr);
        return dp[i] = max(skip,take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        VVI arr;
        n = startTime.size();
        for(int i = 0;i<n;i++){
            arr.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));
        return rec(0,arr);
    }
};