class Solution {
public:
    bool dfs(int node, int currentColor, vector<vector<int>>& adj, vector<int>& color) {
        color[node] = currentColor;
        
        for (int enemy : adj[node]) {
            if (color[enemy] == 0) {
                if (dfs(enemy, -currentColor, adj, color) == false) {
                    return false;
                }
            } 
            else if (color[enemy] == currentColor) {
                return false;
            }
        }
        
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : dislikes) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> color(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                if (dfs(i, 1, adj, color) == false) {
                    return false;
                }
            }
        }
        
        return true;
    }
};