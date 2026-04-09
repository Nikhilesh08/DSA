#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0;
        int n = a.size(), m = b.size();

        // Traverse both arrays simultaneously
        while (i < n && j < m) {
            // If element in 'a' is smaller, move pointer 'i'
            if (a[i] < b[j]) {
                i++;
            } 
            // If element in 'b' is smaller, move pointer 'j'
            else if (a[i] > b[j]) {
                j++;
            } 
            // If elements match, it's a common element
            else {
                // Add to result only if it's the first element or distinct from the last added element
                if (res.empty() || res.back() != a[i]) {
                    res.push_back(a[i]);
                }
                // Move both pointers forward
                i++;
                j++;
            }
        }

        return res;
    }
};