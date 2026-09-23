class Solution {
public:
    vector<vector<int>>ans;
    vector<int>cur_path;
    int dest;
    void dfs(vector<vector<int>>& graph, int i){
        cur_path.push_back(i);
        if(i== dest){
            ans.push_back(cur_path);
        }
        for(int j : graph[i]){
            dfs(graph,j);
            cur_path.pop_back();
        }
    }  
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0;
        dest = graph.size()-1;
        dfs(graph,src);
        return ans;
    }
};