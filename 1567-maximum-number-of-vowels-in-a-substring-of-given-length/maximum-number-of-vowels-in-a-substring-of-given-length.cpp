class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    int maxVowels(string s, int k) {
        unordered_map<char,int>mpp;
        int l=0,r=0,n=s.size();
        int maxi=0,cnt=0;
        while(r<n){
            if(isVowel(s[r])) cnt++;
            if(r-l+1>k){
                if(isVowel(s[l])) cnt--;
                l++;
            }
            maxi=max(maxi,cnt);
            r++;
        }
        return maxi;
    }
};