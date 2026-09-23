class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int target = total - x;
        int ans = -1;
        if(target < 0)return -1;
        int l = 0;
        int sum = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(sum > target){
                sum -= nums[l++];
            }
        if(sum==target){
            ans = max(ans, r-l+1);
            }
        }
        if(ans == -1)return -1;
        return nums.size() - ans;
    }
};