class Solution {
public:
    class DisjointSet{
      public:
      vector<int>parent;
      vector<int>rank;
        DisjointSet(int n){
          parent.resize(n);
          for(int i=0;i<n;i++){
              parent[i]=i;
          }
        rank.resize(n,0);
      }
      
      void Union(int u,int v){
        int rootU = findParent(u);
        int rootV = findParent(v);
            if (rootU == rootV) return;
            if (rank[rootU] == rank[rootV]) {
                parent[rootU] = rootV;
                rank[rootV]++;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] =rootU;
            } else {
                parent[rootU] = rootV;
            }
      }
      
      int findParent(int u){
          if(parent[u]==u){
              return u;
          }
          return parent[u]=findParent(parent[u]);
      }
  };
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        DisjointSet du(n+1);
       vector<vector<int>>adj(n+1);
       for(int i=0;i<dislikes.size();i++){
        int first=dislikes[i][0];
        int second=dislikes[i][1];
        adj[first].push_back(second);
        adj[second].push_back(first);
       }
    for(int i=1;i<n;i++){
       for(int enemy : adj[i]){
        // are we in same grp and enemies !!! dangerrrr
        if(du.findParent(enemy)==du.findParent(i)) return false;
        // we are friends because for enemy is same(i)
        du.Union(adj[i][0],enemy);
       }
       }
       return true;
    }
};