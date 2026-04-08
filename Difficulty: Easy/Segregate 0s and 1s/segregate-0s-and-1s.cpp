class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int low = 0;
        int high = arr.size() - 1;
        
        while (low < high) {
            while (low < high && arr[low] == 0) {
                low++;
            }
            while (low < high && arr[high] == 1) {
                high--;
            }
            if (low < high) {
                swap(arr[low], arr[high]);
                low++;
                high--;
            }
        }
    }
};