
class Solution {
public:
    int binarySearchable(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        
        // Check if each element can be found using standard binary search
        for (int i = 0; i < n; i++) {
            int target = arr[i];
            int l = 0;
            int r = n - 1;
            bool found = false;
            
            while (l <= r) {
                int mid = l + (r - l) / 2;
                
                if (arr[mid] == target) {
                    found = true;
                    break;
                } else if (arr[mid] < target) {
                    // Target is greater, so search space moves right
                    l = mid + 1;
                } else {
                    // Target is smaller, so search space moves left
                    r = mid - 1;
                }
            }
            
            if (found) {
                count++;
            }
        }
        
        return count;
    }
};