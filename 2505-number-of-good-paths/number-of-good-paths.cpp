class Solution {
    class DisjointSet {
    public:
        vector<int> parent, rank;
        DisjointSet(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        int findParent(int node) {
            if(parent[node] == node) {
                return node;
            }
            return parent[node] = findParent(parent[node]); 
        }
        
        void Union(int u, int v) {
            int ult_u = findParent(u);
            int ult_v = findParent(v);
            
            if(ult_u == ult_v) return;
            
            if(rank[ult_u] > rank[ult_v]) {
                parent[ult_v] = ult_u;
            }
            else if(rank[ult_v] > rank[ult_u]) {
                parent[ult_u] = ult_v;
            }
            else {
                parent[ult_v] = ult_u;
                rank[ult_u]++;
            }
        }
    };

public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(); 
        
        vector<vector<int>> adj(n);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        DisjointSet ds(n);
        
        map<int, vector<int>> val_nodes;
        for(int i = 0; i < n; i++) {
            val_nodes[vals[i]].push_back(i);
        }

        vector<int> is_active(n, 0);
        int good_paths = 0;
        
        for(auto& it : val_nodes) {
            vector<int>& nodes_vec = it.second;
            
            for(int node : nodes_vec) {
                for(int neighbor : adj[node]) {
                    if(is_active[neighbor]) {
                        ds.Union(node, neighbor);
                    }
                }
                is_active[node] = 1;
            }
            
            unordered_map<int, int> parent_count;
            for(int node : nodes_vec) {
                int ultimate_parent = ds.findParent(node);
                parent_count[ultimate_parent]++;
            }
            
            for(auto& count_it : parent_count) {
                int count = count_it.second;
                good_paths += (count * (count - 1)) / 2 + count; 
            }
        }
        
        return good_paths;
    }
};