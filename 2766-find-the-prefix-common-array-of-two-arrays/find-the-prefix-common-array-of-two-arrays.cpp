class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mpp;
        int n=A.size();
        vector<int>C(n,0);
         int cnt=0;
        for(int i=0;i<n;i++){
            mpp[A[i]]++;
            if(mpp[A[i]]==2) cnt++;
            mpp[B[i]]++;
            if(mpp[B[i]]==2) cnt++;
            C[i]=cnt;
        }
        return C;
    }
};