class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int completed = 0;
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n,vector<int>(n,0));
        queue<int>q;
        for(int i = 0; i < prerequisites.size();i++){
            adj[prerequisites[i][0]][prerequisites[i][1]]=1;
            indegree[prerequisites[i][1]]++;
        }
        for(int i = 0; i < n; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int i = q.front();
            completed++;
            q.pop();
            for(int j = 0; j < n;j++){
                if(adj[i][j] == 1){
                    adj[i][j] = 0;
                    indegree[j]--;
                    if(indegree[j]==0)
                        q.push(j);
                }
            }
        }
        return completed == n;
    }
};