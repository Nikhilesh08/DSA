class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int n=s.size();
        vector<int>openBrac(n+1,0),closeBrac(n+1,0);
        for(int i=n-1;i>=0;i--){
            if(s[i]==')')closeBrac[i]=closeBrac[i+1]+1;
            else closeBrac[i]=closeBrac[i+1];
        }
        
        // opeBrac[0]=0;
        
        for(int i=1;i<=n;i++){
            if(s[i-1]=='(') openBrac[i]=openBrac[i-1]+1;
            else openBrac[i]=openBrac[i-1];
        }
        
        for(int i=0;i<=n;i++){
            if(openBrac[i]==closeBrac[i]){
                return i;
            }
        }
        return 0;
    }
    
};