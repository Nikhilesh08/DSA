class Solution {
public:
    int maxlen;
    int solve(int root,int parent,vector<vector<int>>&adj,string &s){
        int longest=0;
        int second_longest=0;
        for(auto child : adj[root]){
            if(child!=parent){
                // it returns max len of child
                int child_len=solve(child,root,adj,s);
                if(s[child]!=s[root]){
                    if(child_len > longest){
                        second_longest=longest;
                        longest=child_len;
                    }
                    else if(child_len > second_longest){
                        second_longest=child_len;
                    }
                }
            }
        }
        maxlen=max(maxlen,1+longest+second_longest);
        return 1+longest;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        maxlen=1;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                // root node;
                continue ;
            }
            else{
                adj[i].push_back(parent[i]);
                adj[parent[i]].push_back(i);
            }
        }
        solve(0,-1,adj,s);
        return maxlen;
    }
};