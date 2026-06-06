class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = arr.size();
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            minHeap.push(arr[i]);
            if(minHeap.size() > k) {
                minHeap.pop();
            }
            if(minHeap.size() == k) {
                ans[i] = minHeap.top();
            }
        }
        
        return ans;
    }
};