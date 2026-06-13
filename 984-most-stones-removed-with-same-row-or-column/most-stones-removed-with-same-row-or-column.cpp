class Solution {
public:
    void dfs(int idx,vector<vector<int>>& stones, vector<bool>&vis){
        vis[idx]=true;
        int curr_row=stones[idx][0];
        int curr_col=stones[idx][1];
        for(int i=0;i<stones.size();i++){
            if(!vis[i] &&
            (stones[i][0]==curr_row || stones[i][1]==curr_col)){
                dfs(i,stones,vis);

            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
       vector<bool>vis(n,false);
       int grps=0;
       for(int i=0;i<stones.size();i++){
        if(!vis[i]){
            dfs(i,stones,vis);
            grps++;
        }
       }
       return n-grps;
    }
};