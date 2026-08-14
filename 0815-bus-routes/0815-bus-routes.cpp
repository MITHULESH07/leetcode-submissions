class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        map<int,set<int>>mp;
        vector<vector<int>>adj(routes.size());
        vector<bool>vis(routes.size(),false);
        queue<pair<int,int>>q;
        for(int i = 0;i<routes.size();i++){
            for(int j = 0;j<routes[i].size();j++){
                if(routes[i][j]==source){vis[i]=true;q.push({1,i});}
                if(mp.find(routes[i][j])!=mp.end()){
                    for(int m:mp[routes[i][j]]){
                        adj[m].push_back(i);
                        adj[i].push_back(m);
                    }
                }
                mp[routes[i][j]].insert(i);
            }
        }
    
        while(!q.empty()){
            auto [d,u] = q.front();
            q.pop();
            if(mp[target].count(u)){
                return d;
            }
            for(int v:adj[u]){
                if(vis[v]==false){
                    vis[v]=true;
                    q.push({d+1,v});
                }
            }
        }
        return -1;
    }
};