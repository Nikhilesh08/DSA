class Solution {
public:
    bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i* i <=n; i++)
        if (n % i == 0)  
            return false;
    return true;
}
    int sumOfPrimesInRange(int n) {
        int rev=0;
        int temp=n;
        while(n){
            rev=rev*10+(n%10);
            n=n/10;
        }
        int start=min(temp,rev);
        int end=max(temp,rev);
        int ans=0;
        for(int i=start;i<=end;i++){
            if(isPrime(i)){
                ans+=i;
            }
        }
        return ans;
    }
};