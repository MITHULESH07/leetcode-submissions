class Solution {
public:
    int mod = 1e9+7;
    int lcm(int a,int b){
        int x = a, y = b;
        if(x < y)swap(x,y);
        while(b!=0){
            int rem = a % b;
            a = b;
            b = rem;
        }
        int gcd = a;
        return (x * y) / gcd;
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long l  = min(a,b), h = 1LL*n*min(a,b);
        long long lab = lcm(a,b);
        long long ans = 0;
        while(l <= h){
            long long m = l+(h-l)/2;
            int count = (m/a) + (m/b) - (m/lab);
            if(count >= n){
                ans = m; 
                h = m-1;
            }
            else l = m+1; 
        }
        return ans % mod;
    }
};