class Solution {
public:
    class DisjointSet {
    public:
        vector<int> parent;
        vector<int> rank;
        int components;
        
        DisjointSet(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            rank.resize(n, 0);
            components = n;
        }
        
        void Union(int u, int v) {
            int rootU = findParent(u);
            int rootV = findParent(v);
            
            if (rootU == rootV) return;
            
            components--;
            
            if (rank[rootU] == rank[rootV]) {
                parent[rootV] = rootU;
                rank[rootU]++;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootU] = rootV;
            }
        }
        
        int findParent(int u) {
            if (parent[u] == u) {
                return u;
            }
            return parent[u] = findParent(parent[u]);
        }
    };
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        
        DisjointSet du(n);
        
        for (int i = 0; i < connections.size(); i++) {
            du.Union(connections[i][0], connections[i][1]);
        }
        
        return du.components - 1;
    }
};