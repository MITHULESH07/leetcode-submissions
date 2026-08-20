class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int i = 0,j = n-1;
        ans[0] = nums[0];
        ans[n-1] = nums[1];
        for(int k = 2;k < n;k++){
            if(ans[i]>ans[j]){
                i++;
                ans[i] = nums[k];
            }
            else{
                j--;
                ans[j] = nums[k];
            }
        }
        reverse(ans.begin()+j,ans.end());
        return ans;
    }
};