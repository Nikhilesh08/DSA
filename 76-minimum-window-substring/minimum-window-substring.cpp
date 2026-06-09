class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash(256,0);
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }

        int l=0,r=0,minlen=INT_MAX;
        int cnt=0,sidx=-1;
        while(r<s.size()){
            if(hash[s[r]]>0) cnt++;
            hash[s[r]]--;
            while(cnt==t.size()){
                if(r-l+1 < minlen){
                    minlen=r-l+1;
                    sidx=l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }

        return sidx ==-1 ? "" : s.substr(sidx,minlen);
    }
};