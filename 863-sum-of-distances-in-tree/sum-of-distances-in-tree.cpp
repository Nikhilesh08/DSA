class Solution {
public:
    vector<int> res;
    vector<int> count;
    int N;

    int dfsRoot(int root, int parent, int curr_depth, vector<vector<int>>& adj) {
        res[0] += curr_depth;
        int child_nodes = 0;
        
        for (auto child : adj[root]) {
            if (child != parent) {
                child_nodes += dfsRoot(child, root, curr_depth + 1, adj);
            }
        }
        
        count[root] = 1 + child_nodes;
        return count[root];
    }

    void dfs(int root, int parent, vector<vector<int>>& adj) {
        if (parent != -1) {
            res[root] = res[parent] - count[root] + (N - count[root]);
        }
        
        for (auto child : adj[root]) {
            if (child != parent) {
                dfs(child, root, adj);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        res.assign(n, 0);
        count.assign(n, 0);
        N = n;
        
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        dfsRoot(0, -1, 0, adj);
        dfs(0, -1, adj); 
        
        return res;
    }
};