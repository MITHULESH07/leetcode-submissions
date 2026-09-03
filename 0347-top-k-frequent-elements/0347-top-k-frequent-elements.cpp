class Solution {
public:
    using PII = pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<PII>vec;
        vector<int>ans;
        for(int n : nums){
            mp[n]++;
        }
        for(auto & m : mp){
            vec.push_back({m.first,m.second});
        }
        sort(vec.begin(),vec.end(),[](const PII & a, const PII & b){
            return a.second > b.second;
        });
        for(auto & m : vec){
            k--;
            ans.push_back(m.first);
            if(k==0)break;
        }
        return ans;
    }
};