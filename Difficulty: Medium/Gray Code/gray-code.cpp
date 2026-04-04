class Solution {
  public:
    string toBinStr(int num,int n){
        string str="";
        for(int i=n-1;i>=0;i--){
            if((num>>i)&1){
                str+='1';
            }
            else{
                str+='0';
            }
        }
        return str;
    }
    vector<string> graycode(int n) {
        // code here
        vector<string>ans;
        int totNum=1<<n;
        for(int i=0;i<totNum;i++){
            int grayCode=i^(i>>1);
            ans.push_back(toBinStr(grayCode,n));
        }
        return ans;
    }
};