class Solution {
public:
    int GCD(int a,int b){
        if(b>a)swap(a,b);
        while(b){
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int l = *min_element(nums.begin(),nums.end()),h=*max_element(nums.begin(),nums.end());
            return GCD(l,h);
    }
};