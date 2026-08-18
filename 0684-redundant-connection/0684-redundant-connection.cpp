class Solution {
public:
    vector<int>par;
    int find(int u){
        if(par[u]==u)return u;
        return par[u]=find(par[u]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n+1);
        for(int i = 1;i<=n;i++)par[i]=i;
        for(vector<int> e:edges){
            int u = e[0];
            int v = e[1];
            int pu = find(u);
            int pv = find(v);
            if(pv==pu){
                return {u,v};
            }
            par[pv]=pu;
        }
        return {-1,-1};
    }
};