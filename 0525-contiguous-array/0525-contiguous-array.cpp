class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(nums[i]==0)
            nums[i]=-1; 
        }
        int ans = 0;
        int psum = 0;
        map<int,int>mp;
        for(int i = 0;i < n;i++){
            psum += nums[i];
            if(psum == 0){
                ans = max(ans,i+1);
            }
            else if(mp.find(psum) != mp.end()){
                ans = max(ans, i - mp[psum]);
            }
            else{
                mp[psum] = i;
            }
        }
        return ans;
    }
};