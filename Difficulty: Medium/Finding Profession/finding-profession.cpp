class Solution {
  public:
    char solve(int pos,int level){
        if(pos==1){
            return 'E';
        }
        
        int par_pos;
        if(pos%2==0) par_pos=(pos/2);
        else par_pos=(pos+1)/2;
        char ch=solve(par_pos,level-1);
        if(ch=='E'){
            //E->ED
            if(pos%2==0){
                //even
                return 'D';
            }
            else{
                return 'E';
            }
        }
        else{
            //D->DE
            if(pos%2==0){
                return 'E';
            }
            else{
                return 'D';
            }
        }
        return ' ';
    }
    string profession(int level, int pos) {
        // code here
        char ans=solve(pos,level);
        return ans=='D'?"Doctor":"Engineer";
    }
};