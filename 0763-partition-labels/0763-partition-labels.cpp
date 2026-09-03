class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++){
            mp[s[i]]= i; 
        }
        vector<int>ans;
        int start = 0;
        int limit = mp[s[0]];
        for(int i = 0; i < n; i++){
            if(i > limit){
                ans.push_back(limit - start +1);
                start = i;
            }
            limit = max(limit , mp[s[i]]);
        }
        ans.push_back(limit - start + 1);
        return ans;
    }
};