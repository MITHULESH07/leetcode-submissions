class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 1;
        if(n == 2)return (nums[0]==nums[1])?1:2;
        int diff = 0;
        int curr = 1;
        int maxi = 1;
        for(int i = 1;i < n;i++){
            if(nums[i]-nums[i-1]>0){
                if(i==1 || nums[i-1]-nums[i-2] > 0){
                    curr++;
                }
                else{
                    maxi = max(maxi,curr);
                    curr=2;
                }
            }
            else if(nums[i]-nums[i-1] < 0){
                if(i==1 || nums[i-1]-nums[i-2] < 0){
                    curr++;
                }
                else{
                    maxi = max(maxi,curr);
                    curr=2;
                }
            }
            else{
                maxi = max(maxi,curr);
                curr = 1;
            }
        }
        maxi = max(maxi,curr);
        return maxi;
    }
};