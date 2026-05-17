class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> ans; 
        
        for(int i = 0; i < arr.size(); i++) {
            if(ans.empty()) {
                ans.push_back(arr[i]);
            } 
            else {
                int top = ans.back();
                int current = arr[i];
                
                if ((top >= 0 && current < 0) || (top < 0 && current >= 0)) {
                    ans.pop_back(); 
                } 
                else {
                    ans.push_back(current);
                }
            }
        }
        
        return ans;
    }
};