class Solution {
public:
    int sieve(int n){
        bool prime[5000005];
        memset(prime,true,sizeof(prime));
        int ans = 0;
        prime[0] = false;
        prime[1] = false;
        for(int i = 2;i*i<n;i++){
            if(prime[i]){
                for(int j = i*i;j<n;j+=i)
                    prime[j] = false;
            }
        }
        for(int i = 2;i<n;i++){
            ans += (prime[i]);
        }
        return ans;
    }
    int countPrimes(int n) {
        if(n<=2)return 0;
        return sieve(n);
    }
};