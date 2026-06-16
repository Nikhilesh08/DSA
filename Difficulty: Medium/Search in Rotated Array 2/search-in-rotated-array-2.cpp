class Solution {
  public:
    bool search(vector<int>& arr, int key) {
        // Code here
        int n = arr.size();
        int low = 0, high = n - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] == key) return true;
            if(arr[low] == arr[mid] && arr[mid] == arr[high]){
                low = low + 1;
                high = high - 1;
                continue;
            }
            
            if(arr[low] <= arr[mid]){
                // left sorted
                if(key >= arr[low] && key < arr[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                // right sorted
                if(key > arr[mid] && key <= arr[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
        
    }
};