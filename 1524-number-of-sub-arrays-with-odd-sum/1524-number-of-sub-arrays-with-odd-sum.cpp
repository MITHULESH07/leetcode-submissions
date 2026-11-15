class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        long long odd_count=0, even_count=1;
        long long total = 0, curr = 0;
        for(int a : arr){
            curr += a;
            if(curr%2==1){
                total = (total+even_count)%mod;
                odd_count++;
            }
            else{
                total = (total+odd_count)%mod;
                even_count++;
            }
        }
        return total;
    }
};