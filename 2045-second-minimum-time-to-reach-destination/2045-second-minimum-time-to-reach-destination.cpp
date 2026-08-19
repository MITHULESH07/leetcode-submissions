class Solution {
public:
    using PII = pair<int,int>;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>best(n+1,vector<int>(2,INT_MAX));
        vector<vector<int>>adj(n+1);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        priority_queue<PII,vector<PII>,greater<PII>>pq;
        pq.push({0,1});
        best[1][0]=0;
        while(!pq.empty()){
            auto [t,u] = pq.top();
            pq.pop();
            if((t/change)%2){
                t =(t/change+1)*change;
            }
            int newT = t+time;
            for(int v:adj[u]){
                if(newT < best[v][0]){
                    best[v][1] = best[v][0];
                    best[v][0] = newT;
                    pq.push({newT,v});
                }
                else if(newT<best[v][1] && newT>best[v][0]){
                    best[v][1] = newT;
                    pq.push({newT,v});
                }
            }
        }cout<<best[1][0]<<' '<<best[1][1];
        return best[n][1];
    }
};