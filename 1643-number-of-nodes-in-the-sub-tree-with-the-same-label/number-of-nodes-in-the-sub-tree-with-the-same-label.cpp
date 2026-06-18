class Solution {
public:
    vector<int>ans;
    vector<int>dfs(int root,string &labels,int parent,vector<vector<int>>&adj){

         vector<int>my_cnt(26,0);
            int my_label=labels[root]-'a';
            my_cnt[my_label]=1;

        for (auto child : adj[root]){
            if(child!=parent){
                vector<int>child_cnt=dfs(child,labels,root,adj);
                for(int i=0;i<26;i++){
                    my_cnt[i]+=child_cnt[i];
                }
            }
        }
          ans[root]=my_cnt[my_label];
            return my_cnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n,0);
        vector<vector<int>>adj(n);
        for(auto it :edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,labels,-1,adj);
        return ans;
    }
};