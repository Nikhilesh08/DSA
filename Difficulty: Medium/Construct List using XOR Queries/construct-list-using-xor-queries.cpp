class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int>ans;
        ans.push_back(0);
        unordered_map<int,int>mpp;
        for(int i=0;i<queries.size();i++){
            int num=queries[i][1];
            if(queries[i][0]==0){
                ans.push_back(num);
            }
            else{
                int idx=ans.size()-1;
                if(mpp.find(idx)!=mpp.end()){
                    mpp[idx]=mpp[idx]^num;
                }
                else{
                    mpp[idx]=num;
                }
            }
        }
        
        int prev=0;
        int n=ans.size();
        for(int i=n-1;i>=0;i--){
            if(mpp.find(i)!=mpp.end()){
                prev=prev^mpp[i];
            }
            ans[i]=ans[i]^prev;
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};
