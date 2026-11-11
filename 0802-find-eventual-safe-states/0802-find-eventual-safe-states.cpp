class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int  n = graph.size();
        vector<int>ans;
        vector<vector<int>>par(n);
        vector<int>outdegree(n,0);
        queue<int>q;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < graph[i].size();j++){
                outdegree[i]++;
                par[graph[i][j]].push_back(i);
            }
            if(outdegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int j = q.front();
            q.pop();
            for(int i : par[j]){
                outdegree[i]--;
                if(outdegree[i]==0)
                    q.push(i);
            }
        }
        for(int i = 0; i <n;i++){
            if(outdegree[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};