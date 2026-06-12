class Solution {
public:
    class DisjointSet {
    public:
        vector<int> parent;
        
        // No rank array needed for this platform's naive logic
        DisjointSet(int n) {
            parent.resize(n);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        void Union(int u, int v) {
            int rootU = findParent(u);
            int rootV = findParent(v);
            
            if (rootU == rootV) return;
            
            // Blindly attach the first set to the second set
            parent[rootU] = rootV; 
        }
        
        int findParent(int u) {
            if (parent[u] == u) {
                return u;
            }
            // Keep Path Compression, it's still safe and fast!
            return parent[u] = findParent(parent[u]);
        }
    };
    
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        DisjointSet du(n + 1);
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            if(queries[i][0] == 1) {
                du.Union(queries[i][1], queries[i][2]);
            } else {
                ans.push_back(du.findParent(queries[i][1]));
            }
        }
        return ans;
    }
};