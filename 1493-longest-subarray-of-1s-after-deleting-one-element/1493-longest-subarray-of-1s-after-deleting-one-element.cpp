class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int one = 0;
        int zero = 0;
        int ans = 0;
        for(int r = 0; r < n; r++){
            if(nums[r]==0){
                zero++;
            }
            else{
                one++;
            }
            while(zero > 1){
                if(nums[l]==0){
                    zero--;
                }else{
                    one--;
                }
                l++;
            }
            ans = max((zero == 0 ? one-1 : one),ans);
        }
        return ans;
    }
};