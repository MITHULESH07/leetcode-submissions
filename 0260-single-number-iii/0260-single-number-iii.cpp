class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a =0 ,b=0;
        int txor = 0;
        for(int x:nums){
            txor ^= x;
        }
        int r = txor & (~(unsigned int)txor+1);
        cout<<r;
        for(int x:nums){
            if(x & r){
                a ^= x;
            }
            else{
                b^= x;
            }
        }
        return {a,b};
    }
};