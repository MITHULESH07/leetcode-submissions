class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int>mp;
        int l=0;
        for(vector<string>acc:accounts){
            int par = INT_MAX;
            for(int i = 1;i<acc.size();i++){
                if(mp.count(acc[i])==0){
                    mp[acc[i]]=l;
                }
                else{
                    par = min(par,mp[acc[i]]);
                }
            }
            l++;
            if(par!=INT_MAX){
                for(int i = 1;i<acc.size();i++){
                    int xpar = mp[acc[i]];
                    if(xpar!=par){
                        mp[acc[i]]=par;
                        for(auto m:mp){
                            if(m.second==xpar){
                                mp[m.first]=par;
                            }
                        }
                    }
                }
            }
        }
        map<int,vector<string>>mpp;
        for(auto m:mp){
            if(mpp.count(m.second)==0)mpp[m.second].push_back(accounts[m.second][0]);
            mpp[m.second].push_back(m.first);
        }
        vector<vector<string>>ans;
        for(auto m:mpp){
            ans.push_back(m.second);
        }
        return ans;
    }
};