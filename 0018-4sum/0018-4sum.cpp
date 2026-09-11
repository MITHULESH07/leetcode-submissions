class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums,int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i < n-3;i++){
            if(i>0 && nums[i-1]==nums[i])continue;
            for(int j = i+1; j < n-2;j++){
                if(j>i+1 && nums[j-1] == nums[j])continue;
                long long ntarget = 1ll * target - nums[i] - nums[j];
                int l = j+1, h = n-1;
                while(l < h){
                    long long sum = nums[l]+nums[h]; 
                    if(sum == ntarget){
                        ans.push_back({nums[i],nums[j],nums[l],nums[h]});
                        l++;
                        h--;
                        while(l<n && nums[l]==nums[l-1])
                        l++; 
                        while(h>=0 && nums[h]==nums[h+1])
                        h--;
                    }
                    else{
                        if(sum < ntarget){
                            l++;
                        }
                        else{
                            h--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};