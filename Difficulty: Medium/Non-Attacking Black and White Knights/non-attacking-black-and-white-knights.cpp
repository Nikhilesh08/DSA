class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
         int total=(n*m)*(n*m-1);
         int ways=0;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 // 1way
                 int delRow[]={-1,+1,-1,+1};
                 int delCol[]={-2,+2,+2,-2};
                 for(int k=0;k<4;k++){
                     int nrow=i+delRow[k];
                     int ncol=j+delCol[k];
                     if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                         ways++;
                     }
                 }
                 
                 // 2way
                 int delRow1[]={-2,+2,-2,+2};
                 int delCol1[]={-1,+1,+1,-1};
                 for(int k=0;k<4;k++){
                     int nrow=i+delRow1[k];
                     int ncol=j+delCol1[k];
                     if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                         ways++;
                     }
                 }
                 
             }
         }
         return total-ways;
    }
};