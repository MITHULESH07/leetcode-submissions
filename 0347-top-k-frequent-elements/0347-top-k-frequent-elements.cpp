class Solution {
public:
    using PII = pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        priority_queue<PII>pq;
        vector<int>ans;
        for(int n : nums){
            mp[n]++;
        }
        for(auto m : mp){
            pq.push({m.second,m.first});
        }
        while(k-- && pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};