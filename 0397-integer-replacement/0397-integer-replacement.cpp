class Solution {
public:
    int integerReplacement(int n) {
       int ans = 0;
       long long nums = n;
       while(nums >1){
        if((nums & 1)==0){
            nums >>= 1;
        }
        else{
            if(nums==3 || (nums & 3) ==1){
                nums--;
            }
            else{
                nums++;
            }
        } 
        ans++;
        }
        return ans;
    }
};