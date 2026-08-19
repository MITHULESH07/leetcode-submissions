class Solution {
public:
    double bfs(string s,string d,map<string,vector<pair<string,double>>>adj,vector<double>&ans){
        queue<pair<double,string>>q;
        map<string,bool>vis;
        for(auto m:adj){
            vis[m.first]=false;
        }
        for(auto [v,m]:adj[s]){
            if(v==d){
                return m; 
            }
        }
        if(adj.count(s))
            q.push({1.00,s});
        while(!q.empty()){
            auto [m,u] = q.front();
            q.pop();
            for(auto [v,x]:adj[u]){
                if(v==d){
                    adj[s].push_back({d,m*x});
                     return m*x;
                }
                if(!vis[v]){
                    vis[v]=true;
                    q.push({m*x,v});
                }
            }
        }
        return -1.00;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>>adj;
        vector<double>ans(queries.size(),-1.00);
        for(int i = 0;i<equations.size();i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        int i =0;
        for(vector<string> s:queries){
            ans[i++] = bfs(s[0],s[1],adj,ans);
        }
        return ans;
    }
};