class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        unordered_map<string,int>mpp;
        int n=s.size();
        if(n%k!=0) return false;
        for(int i=0;i<n;i+=k){
            mpp[s.substr(i,k)]++;
        }
        if(mpp.size()==1) return true;
        if(mpp.size()!=2) return false;
        if(mpp.begin()->second==(n/k-1) || mpp.begin()->second==1) return true;
        return false;
    }
};