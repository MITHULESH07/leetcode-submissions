class Solution {
public:
    int sieve(int n){
        vector<char>prime(n,'1');
        int ans = 0;
        prime = prime ;
        prime[1] = false;
        for(int i = 2;i*i<n;i++){
            if(prime[i]=='1'){
                for(int j = i*i;j<n;j+=i)
                    prime[j] = '0';
            }
        }
        for(int i = 2;i<n;i++){
            ans += (prime[i]=='1');
        }
        return ans;
    }
    int countPrimes(int n) {
        if(n<=2)return 0;
        return sieve(n);
    }
};