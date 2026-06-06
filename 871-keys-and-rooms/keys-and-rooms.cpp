class Solution {
public:
    void dfs(int idx,vector<vector<int>>&adj,vector<int>&vis){
        vis[idx]=1;
        for(auto it : adj[idx]){
            if(!vis[it])dfs(it,adj,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            vector<int>vec=rooms[i];
            for(int j=0;j<vec.size();j++){
            adj[i].push_back(vec[j]);
            }
        }
        vector<int>vis(n,0);
        dfs(0,adj,vis);
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};