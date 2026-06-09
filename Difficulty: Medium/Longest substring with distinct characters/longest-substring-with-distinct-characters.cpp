class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int l=0,r=0,n=s.size();
        vector<int>hash(26,-1);
        int maxlen=0;
        while(r<n){
            if(hash[s[r]-'a']!=-1){
                if(hash[s[r]-'a']>=l){
                l=hash[s[r]-'a']+1;
                }
            }
            hash[s[r]-'a']=r;
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
