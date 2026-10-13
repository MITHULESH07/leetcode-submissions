class Solution {
public:
    bool static comp(int&a, int&b){
        return a > b;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = 0;
        for(int & a : nums){
            a = a*a;
        }
        sort(nums.begin(),nums.end(),comp);
        // for(int & a : nums){
        //     cout<<a<<" ";
        // }
        int l = 0, r = nums.size()-1;
        while(l <= r){
            sum += nums[l];
            l++;
            if(l <= r){
                sum -= nums[r];
            }
            r--;
        }
        return sum;
    }
};