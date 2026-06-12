class Solution {
public:
    int MOD=1e9+7;
    long long power(long long  base,long long exp){
        long long ans=1;
        base=base%MOD;
        while(exp>0){
        if(exp%2!=0){
            ans=(ans*base)%MOD;
            exp=exp-1;
        }
        else{
            base=(base*base)%MOD;
            exp=exp/2;
        }
        }
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
     int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int max_depth = 0;
        queue<pair<int, int>> q; 
        vector<bool> visited(n + 1, false);
        q.push({1, 0});
        visited[1] = true;
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            max_depth = max(max_depth, depth);
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, depth + 1});
                }
            }
        }
        if (max_depth == 0) return 0;
        return power(2, max_depth - 1);
    }
};