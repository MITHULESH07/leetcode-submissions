class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        if(k==1){
            for(int n:nums){
                mp[n]++;
            }
            int ans = -1;
            for(auto m:mp){
                if(m.second==1)
                ans = max(ans,m.first);
            }
            return ans;
        }
        if(n==k){
            return *max_element(nums.begin(),nums.end());
        }
        int ans1 = nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i]==nums[0]){
                ans1 = -1;
                break;
            }
        }
        int ans2 = nums[n-1];
        for(int i = n-2;i>=0;i--){
            if(nums[i]==nums[n-1]){
                ans2 = -1;
                break;
            }
        }
        return max(ans1,ans2);
            
    }
};