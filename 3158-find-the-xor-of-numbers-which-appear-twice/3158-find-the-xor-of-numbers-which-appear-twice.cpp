class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        long long vis = 0;
        for(int n : nums){
            if(vis & (1LL<<n))ans^=n;
            else vis |= (1LL<<n);
        }
        return ans;
    }
};