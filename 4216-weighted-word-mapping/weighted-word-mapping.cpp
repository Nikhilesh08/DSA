class Solution {
public:
    int solve(string &words,vector<int>& weights){
        int wt=0;
        for(int i=0;i<words.size();i++){
            wt+=weights[words[i]-'a'];
        }
        return wt%26;
    }
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(int i=0;i<words.size();i++){
            int wt=solve(words[i],weights);
            ans+=('a'+(26-wt-1));
        }
        return ans;
    }
};