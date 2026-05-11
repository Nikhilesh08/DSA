class Solution {
  public:
     bool isPalindrome(string s){
        int left=0;
        int right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    bool palindromePair(vector<string>& arr) {
         unordered_map<string,int>mpp;
         for(auto it:arr) mpp[it]++;
         
         for(int i=0; i<arr.size(); i++){
             string word = arr[i];
             int len = word.size();
             
             for(int j=0; j<=len; j++){
                 string left = word.substr(0, j);
                 string right = word.substr(j);
                 
                 if(isPalindrome(right)){
                     string revLeft = left;
                     reverse(revLeft.begin(), revLeft.end());
                     if(mpp.count(revLeft)) {
                         if(revLeft != word || mpp[revLeft] > 1){
                             return true;
                         }
                     }
                 }
                 
                 if(isPalindrome(left)){
                     string revRight = right;
                     reverse(revRight.begin(), revRight.end());
                     
                     if(mpp.count(revRight)) {
                         if(revRight != word || mpp[revRight] > 1){
                             return true;
                         }
                     }
                 }
             }
         }
         return false;
    }
};