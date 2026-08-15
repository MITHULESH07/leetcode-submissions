class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0,zeros = 0,n = nums.size();
        for(int x:nums){
            if(x==0)zeros++;
            total = total^x;
        }
        if(total)return nums.size();
        if(zeros == n)return 0;
        return n-1;
    }
};