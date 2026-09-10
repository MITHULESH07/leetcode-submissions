class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000)return 0;
        long long ans = 0;
        long long i;
        for(i = 1000; i <= n; i*=1000  ){
            ans += (n-i+1);
            cout<<n-i+1<<endl;
        }
        return ans;
    }
};