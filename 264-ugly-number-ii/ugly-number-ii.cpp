class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr(n+1);
        // 1st ugly number
        arr[1]=1;
        int i2=1,i3=1,i5=1;
        for(int i=2;i<=n;i++){
            int next2=arr[i2]*2;
            int next3=arr[i3]*3;
            int next5=arr[i5]*5;
            int nextUgly = min(next2, min(next3, next5));
            arr[i] = nextUgly;

            if (nextUgly == next2) i2++;
            if (nextUgly == next3) i3++;
            if (nextUgly == next5) i5++;
        }
        return arr[n];
    }
};