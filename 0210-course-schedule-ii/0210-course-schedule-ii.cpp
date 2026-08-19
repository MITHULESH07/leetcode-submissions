class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(vector<int>p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int>q;  
        vector<int>ans;
        for(int i = 0;i<n;i++){
            if(indeg[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            ans.push_back(u);
            q.pop();
            for(int v:adj[u]){
                indeg[v]--;
                if(indeg[v]==0)q.push(v);
            }
        }
        if(ans.size()!=n)return {};
        return ans;
    }
};