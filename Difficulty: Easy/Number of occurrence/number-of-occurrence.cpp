class Solution {
  public:
    int upper_bound(vector<int>& arr,int target){
        int n=arr.size();
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    
    int lower_bound(vector<int>& arr,int target){
        int n=arr.size();
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        
        // upper bound-lower bound
        return upper_bound(arr,target)-lower_bound(arr,target);
    }
};
