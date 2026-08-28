class Solution {
public:
    long long lcm(long long a,long long b){
        return a*b/(gcd(a,b));
    }
    int nthUglyNumber(int n, int a, int b, int c) {
       int l = 1,h = 2e9;
       int ans = 0;
       long long lab = lcm(a,b);
       long long lac = lcm(a,c);
       long long lbc = lcm(b,c);
       long long labc = lcm(lcm(a,b),c);
       while(l<=h){
        long long m = l+(h-l)/2;
        long long count = (m/a)+(m/b)+(m/c)-(m/lab)-(m/lbc)-(m/lac)+(m/labc);
        if(count >= n){
            ans = m;
            h = m-1;
        } 
        else l = m+1;
       }
       return ans;
    }
};