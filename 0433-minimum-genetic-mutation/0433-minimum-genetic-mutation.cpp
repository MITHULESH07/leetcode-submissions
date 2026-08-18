class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene)return 0;
        int n = bank.size();
        map<string,bool>mp;
        for(string b:bank){
            mp[b]=true;
        }
        char arr[] = {'A','C','G','T'};
        queue<pair<string,int>>q;
        q.push({startGene,0});
        while(!q.empty()){
            auto [s,d] = q.front();
            q.pop();
            for(int j = 0;j<s.length();j++){
                char c = s[j];
                for(int i = 0;i<4;i++){
                    s[j] = arr[i];
                    if(mp.find(s)!=mp.end() && mp[s]){
                        if(s==endGene)return d+1;
                        mp[s]=false;
                        q.push({s,d+1});
                    }
                }
                s[j] = c;
            }
        }
        return -1;
    }
};