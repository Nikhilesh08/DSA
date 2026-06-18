class Solution {
public:
    char processStr(string s, long long k) {
        long long len=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(len>0) len--;
            }
            else if(s[i]=='#'){
                len*=2;
            }
            else if(s[i]=='%'){
                // no change in len
                continue;
            }
            else{
                // normal lower case
                len++;
            }
        }

        if(k>=len) return '.';

        for(int i =n-1;i>=0;i--){
            if(s[i]=='*'){
                len++;
            }
            else if(s[i]=='#'){
                len=len/2;
                if(k>=len) k=k-len;
            }
            else if(s[i]=='%'){
                k=len-k-1;
            }
            else{
                len--;
            }
            if(len==k) return s[i];
        }
        return '.';
    }
};