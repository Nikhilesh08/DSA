class Solution {
  public:
    void Lps(vector<int> &b,vector<int>&lps,int m){
        int len=0;
        lps[0]=0;
        int i=1;
        while(i<m){
            if(b[i]==b[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        int n=a.size();
        int m=b.size();
        vector<int>lps(m,0);
        vector<int>ans;
        Lps(b,lps,m);
        int i=0;
        int j=0;
        while(i<n){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            if(j==m){
                ans.push_back(i-m);
                j=lps[j-1];
            }
            else if(a[i]!=b[j]){
                if(j!=0)j=lps[j-1];
                else i++;
            }
        }
        return ans;
    }
};