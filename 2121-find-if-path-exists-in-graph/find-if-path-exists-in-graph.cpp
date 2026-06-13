class Solution {
public:
    bool dfs(int idx,vector<vector<int>>&adj,vector<int>&vis,int end){
        vis[idx]=1;
        if(idx==end) return true;
        for(auto it : adj[idx]){
            if(!vis[it]){
            if(dfs(it,adj,vis,end)==true) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        return dfs(source,adj,vis,destination);
    }
};