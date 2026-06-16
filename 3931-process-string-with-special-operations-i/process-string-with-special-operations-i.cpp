class Solution {
public:
    string processStr(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(islower(ch)){
                res+=ch;
            }
            else if(ch=='*'){
                if(!res.empty())res.pop_back();
            }
            else if(ch=='#'){
                res+=res;
            }
            else{
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};