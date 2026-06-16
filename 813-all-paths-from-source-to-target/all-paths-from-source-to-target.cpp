class Solution {
public:
    int n;
    void dfs(int node, vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& ds){
        ds.push_back(node);
        if(node == n - 1){
            ans.push_back(ds);
        } else {
            for(auto it : graph[node]){
                dfs(it, graph, ans, ds);
            }
        }
        ds.pop_back(); 
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<int>> ans;
        vector<int> ds;
        dfs(0, graph, ans, ds);
        
        return ans;
    }
};