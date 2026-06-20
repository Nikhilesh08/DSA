class Solution {
public:
    vector<int>bfs(int node,vector<int>&edges){
        int n=edges.size();
        vector<int>dis(n,1e9);
        dis[node]=0;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            if(edges[top]!=-1){
                int adj=edges[top];
                if(dis[adj] > 1+dis[top]){
                    dis[adj]=1+dis[top];
                    q.push(adj);
                }
            }
        }
        return dis;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int>dis1=bfs(node1,edges);
        vector<int>dis2=bfs(node2,edges);
        int mini=1e9,ans=-1;
        int n=edges.size();
        for(int i=n-1;i>=0;i--){
            if(dis1[i]!=1e9 && dis2[i]!=1e9){
                dis1[i]=max(dis1[i],dis2[i]);
                if(dis1[i]<=mini){
                mini=dis1[i];
                ans=i;
                }
            }
        }
        return ans;
    }
};