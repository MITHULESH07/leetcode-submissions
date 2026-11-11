class Solution {
public:
    using PII = pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<PII>>adj(n+1);
        vector<int>dist(n+1,INT_MAX);
        priority_queue<PII,vector<PII>,greater<PII>>q;
        for(vector<int> t : times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        q.push({0,k});
        dist[k]=0;
        while(!q.empty()){
            auto [d,u] = q.top();
            q.pop();
            for(auto[v,w]:adj[u]){
                if(d+w < dist[v]){
                    dist[v] = d+w;
                    q.push({dist[v],v});
                }
            }
        }
        int ans = -1;
        for(int i = 1; i <= n;i++){
            if(dist[i]==INT_MAX)return -1;
            // if(i!=k)
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};