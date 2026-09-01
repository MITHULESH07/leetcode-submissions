class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int ans = 0;
        int preSum = 0;
        mp[0] = 1;
        for(int i = 0; i < nums.size();i++){
            preSum += nums[i];
            if(mp.find(preSum-k)!=mp.end()){
                ans += mp[preSum - k];
            }
            mp[preSum]++;
        }
        return ans;
    }
};