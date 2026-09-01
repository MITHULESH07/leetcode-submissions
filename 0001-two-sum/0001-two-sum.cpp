class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size() ; i++){
            int a = nums[i];
            if(mp.find(target-a)!=mp.end()){
                return {mp[target-a], i};
            }
            mp[a] = i;
        }
        return {-1,-1};
    }
};