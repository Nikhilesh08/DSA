#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coin(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        // Continue until only one coin remains
        while (left < right) {
            // Greedy strategy: compare the two ends
            if (arr[left] >= arr[right]) {
                // Pick the left coin
                left++;
            } else {
                // Pick the right coin
                right--;
            }
        }

        // Return the value of the last remaining coin
        return arr[left];
    }
};