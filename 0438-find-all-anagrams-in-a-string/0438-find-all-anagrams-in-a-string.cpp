class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.length();
        int m = p.length();
        unordered_map<char,int>mp,ms;
        int l = 0;
        for(char c :p){
            mp[c]++;
        }
        for(int r = 0; r < n; r++){
            ms[s[r]]++;
            while((mp.find(s[r])==mp.end() && l <= r) || (ms[s[r]]>mp[s[r]])){
                ms[s[l++]]--;
            }
            if((r-l+1)==m){
                ans.push_back(l);
            }
        }
        return ans;
    }
};