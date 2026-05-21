class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st1, st2;
        int maxi = 0;

        for(int i = 0; i < arr1.size(); i++){
            string temp = to_string(arr1[i]);
            for(int l = 1; l <= temp.size(); l++){
                st1.insert(temp.substr(0, l));
            }
        }
        
        for(int i = 0; i < arr2.size(); i++){
            string temp = to_string(arr2[i]);
            for(int l = 1; l <= temp.size(); l++){
                st2.insert(temp.substr(0, l));
            }
        }
        
        for(auto temp : st1){
            if(st2.find(temp) != st2.end()){
                int len = temp.size();
                maxi = max(maxi, len);
            }
        }
        return maxi;
    }
};