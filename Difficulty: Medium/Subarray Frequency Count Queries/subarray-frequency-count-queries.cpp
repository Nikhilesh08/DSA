class Solution {
  public:
    int leftBoundary(vector<int>&v,int target){
        int low=0;
        int high=v.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(v[mid]==target) return mid;
            // (first index>=target)
            else if(v[mid]<target) low=mid+1;
            else{
                ans=mid;
                high=mid-1;
            }
            
        }
        return ans;
    }
    int rightBoundary(vector<int>&v,int target){
        int low=0;
        int high=v.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(v[mid]==target) return mid;
            // (last index<=target)
            else if(v[mid]<target){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        return ans;
    }
    
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        map<int,vector<int>>mpp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }
        
        int q=queries.size();
        vector<int>ans(q,0);
        for(int i=0;i<q;i++){
            int val=queries[i][2];
            int start=queries[i][0];
            int end=queries[i][1];
            if(mpp.find(val) == mpp.end()) {
                ans[i] = 0;
                continue;
            }
            int left=leftBoundary(mpp[val],start);
            int right=rightBoundary(mpp[val],end);
            if(left == -1 || right == -1 || left > right) {
                ans[i] = 0;
            } else {
                ans[i] = right - left + 1;
            }
            
        }
        return ans;
    }
};