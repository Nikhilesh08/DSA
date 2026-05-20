class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        unordered_map<int,int>mpp;
        for(auto num : arr){
            mpp[num]++;
        }
        for(int i=0;i<arr.size();i++){
          
          if(arr[i]==0){
              if(target==0 && mpp.size()>1) return true;
              continue;
          }
          if(target%arr[i] !=0){
              continue;
          }
          
          long long find=target/arr[i];
            if(find==arr[i] && mpp[arr[i]]>1){
                return true;
            }
            else if(find!=arr[i] && mpp[find]>=1){
                return true;
            }
        }
        return false;
    }
};