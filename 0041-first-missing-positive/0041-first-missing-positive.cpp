class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int idx = lower_bound(nums.begin(),nums.end(),1) - nums.begin();
        int val = 1;
        for(int i = idx; i < n; i++){
            if(nums[i]==val)val++;
            else if(nums[i] > val)return val;
        }
        return val;
    }
};