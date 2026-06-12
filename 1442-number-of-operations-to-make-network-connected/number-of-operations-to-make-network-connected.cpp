class Solution {
public:
   class DisjointSet {
    public:
        vector<int> parent;
        vector<int> rank;
        DisjointSet(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            rank.resize(n, 0);
        }
        int Union(int u, int v) {
            int rootU = findParent(u);
            int rootV = findParent(v);
            if (rootU == rootV) return 1;
            if (rank[rootU] == rank[rootV]) {
                parent[rootV] = rootU;
                rank[rootU]++;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootU] = rootV;
            }
            return 0;
        }
        int findParent(int u) {
            if (parent[u] == u) {
                return u;
            }
            return parent[u] = findParent(parent[u]);
        }
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        int more=0;
        DisjointSet du(n);
        for(int i=0;i<connections.size();i++){
            if(du.Union(connections[i][0],connections[i][1])==1){
                more++;
            }
        }
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(du.findParent(i));
        }
        int components=st.size();
        int req=components-1;
        if(req<connections.size()){
            if(more>=req) return req;
        }
        return -1;
    }
};