class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n=s.size();
        vector<int>dis(n,-1);
        int cnt=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt=0;
                dis[i]=0;
            }
            else if(cnt!=-1){
                cnt++;
                dis[i]=cnt;
            }
        }
        cnt=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                cnt=0;
                dis[i]=0;
            }
            else if(cnt!=-1){
                cnt++;
                if(dis[i]!=-1)dis[i]=min(cnt,dis[i]);
                else dis[i]=cnt;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1' || (dis[i]>0 && dis[i]<=x)) ans++;
        }
        return ans==s.size();
        
    }
};