class Solution {
public:
    int sum1(int n){
        int sum = 0;
        while(n>0){
            int last = n%10;
            sum += (last * last);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int>seen;
        while(n>1){
            if(seen.count(n))return false;
            seen.insert(n);
            n = sum1(n);
        }
        return true;
    }
};