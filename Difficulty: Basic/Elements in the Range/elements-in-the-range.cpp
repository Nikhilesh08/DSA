class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        unordered_set<int>st;
        st.insert(arr.begin(),arr.end());
        for(int i=start;i<=end;i++){
            if(st.find(i)==st.end()) return false;
        }
        return true;
    }
};
