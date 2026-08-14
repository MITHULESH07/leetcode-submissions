class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>best(n,-1.0);
        priority_queue<pair<double,int>>q;
        vector<vector<pair<int,double>>>adj(n);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        best[start_node]=0.0;
        q.push({1.0,start_node});
        while(!q.empty()){
            auto [d,u] = q.top();
            q.pop();
            for(auto [v,p]:adj[u]){
                if(d*p>best[v]){
                    best[v] = d*p;
                    q.push({best[v],v});
                }
            }
        }
        return best[end_node]<0.0?0.0:best[end_node];
    }
};