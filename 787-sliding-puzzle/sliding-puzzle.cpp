class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string res="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                res+=to_string(board[i][j]);
            }
        }
        unordered_map<int,vector<int>>mpp;
        mpp[0]={1,3};
        mpp[1]={0,2,4};
        mpp[2]={1,5};
        mpp[3]={0,4};
        mpp[4]={1,3,5};
        mpp[5]={2,4};
        unordered_set<string>visited;
        visited.insert(res);
        queue<string>q;
        q.push(res);
        int level=0;
        string target="123450";

        while(!q.empty()){
            int sz=q.size();
            // iterate on each level
            for(int i=0;i<sz;i++){

                string curr=q.front();
                if(curr==target) return level;
                q.pop();

                int zeroInd=curr.find('0');
                
                for(int nextInd :mpp[zeroInd]){
                    string newStr=curr;
                    swap(newStr[nextInd],newStr[zeroInd]);
                    if(visited.find(newStr)==visited.end()){
                        q.push(newStr);
                        visited.insert(newStr);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};