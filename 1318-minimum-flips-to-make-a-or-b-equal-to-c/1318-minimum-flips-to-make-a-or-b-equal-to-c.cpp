class Solution {
public:
    int minFlips(int a, int b, int c) {
        int d = a|b;
        int xr = d ^ c;
        int ans = 0;
        while(xr){
            int rm = xr & (-xr);
            if(!(c & rm)){
                if((a & rm)){
                    ans++;
                }
                if((b & rm)){
                    ans++;
                }
            }else{
                ans++;
            }
            xr = xr & (xr-1);
        }
        return ans;
    }
};