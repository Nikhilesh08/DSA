class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        int target=1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]>target) return target;
            else{
                // arr[i]<=target adds to old sums(1 to target-1)
                target=target+arr[i];
            }
        }
        return target;
    }
};