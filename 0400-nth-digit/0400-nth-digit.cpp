class Solution {
public:
    int findNthDigit(int n) {
        int start = 1;
        long long digit = 9,len = 1;
        while(digit * len < n){
            n -= digit*len;
            digit *= 10;
            len++;
            start *= 10 ;
        }
        start += (n-1)/len;
        int i = (n-1)%len;
        string s = to_string(start);
        return s[i]-'0';
    }
};