class Solution {
public:
    vector<int>par;
    int find_parent(int u){
        if(par[u]==u)return u;
        return par[u] = find_parent(par[u]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>to_be_removed;
        int n = edges.size();
        par.resize(n+1,-1);
        for(int i = 1; i <= n;i++)
            par[i]=i;
        for(int i = 0; i < n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int pu = find_parent(u);
            int pv = find_parent(v);
            if(pu == pv)return {u,v};
            par[pv] = pu;
        }
        return{-1,-1};
    }
};