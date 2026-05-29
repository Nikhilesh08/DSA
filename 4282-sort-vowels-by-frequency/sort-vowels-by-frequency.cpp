class Solution {
public:
    string sortVowels(string s) {
        vector<int>freq(26,0),first(26,-1);
        vector<char>unique;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                if(first[s[i]-'a']==-1){
                    first[s[i]-'a']=i;
                    unique.push_back(s[i]);
                }
                freq[s[i]-'a']++;

            }
        }
        sort(unique.begin(),unique.end(),[&](char a ,char b){
            if(freq[a-'a']!=freq[b-'a']){
                return freq[a-'a']>freq[b-'a'];
            }
            return first[a-'a']<first[b-'a'];
        });

        int idx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                char ch=unique[idx];
                s[i]=ch;
                freq[ch-'a']--;
                if(freq[ch-'a']==0){
                    idx++;
                }
            }
        }
        return s;
    }
};