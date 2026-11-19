class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<=3)return 0;
        sort(nums.begin(),nums.end());
        int min1 = nums[0];
        int max1 = nums[n-1];
        int min2 = nums[1];
        int max2 = nums[n-2];
        int min3 = nums[2];
        int max3 = nums[n-3];
        return min(abs(max3-min1),min(abs(max2-min2),abs(max1-min3)));
    }
};