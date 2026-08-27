class Solution {
public:
    int getSum(int a, int b) {
        int ans = a ^ b;
        int carry = (a & b) << 1;
        b = carry;
        while(b){
            carry = (ans & b) << 1;
            ans = ans ^ b;
            b = carry;
        }
        return ans;
    }
};