class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int xi=0;
        int yi=0;
        int dir=0;
        int n=commands.size();
        int maxDist=0;
        // N,E,S,W
        vector<pair<int,int>>directions={
            {0,1},{1,0},{0,-1},{-1,0}
        };

        set<pair<int,int>>obstac;
        for(auto it: obstacles){
            obstac.insert({it[0],it[1]});
        }

        for(int i=0;i<n;i++){
            if(commands[i]==-1){
                // right 90degree
                dir=(dir+1)%4;
            }
            else if (commands[i]==-2){
                //left 90degree
                dir=(dir-1+4)%4;
            }
            else{
                // shifting commands
                while(commands[i]--){
                    int nx=xi+directions[dir].first;
                    int ny=yi+directions[dir].second;
                    if(obstac.count({nx,ny})) break;
                    xi=nx;
                    yi=ny;
                    maxDist=max(maxDist,xi*xi+yi*yi);
                }
            }


        }
        return maxDist;
        
    }
};