class Solution {
  public:
  bool isPower2(int n){
      return (n>0) && ((n & n-1)==0);
  }
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n=s.size();
        if(isPower2(n))k=k/2;
        else k=k*2;
        stack<char>st;
        if(k>=n) return "-1";
        for(int i=0;i<s.size();i++){
            char curr=s[i];
            while(!st.empty() && curr < st.top() && k>0){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            char ch=st.top();
            ans+=ch;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.empty()) return "-1";
        return ans;
    }
};