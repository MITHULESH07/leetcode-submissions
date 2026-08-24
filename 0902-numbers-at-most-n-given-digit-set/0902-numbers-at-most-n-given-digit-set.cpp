class Solution {
public:
    int dp[20][2][2];
    int n;
    vector<int>num,digit;

    int rec(int j,bool isTight,bool leadingZero){
        if(j==n)return !leadingZero;
        if(dp[j][isTight][leadingZero]!=-1)return dp[j][isTight][leadingZero];
        int limit = isTight?num[j]:9;
        int ans  =0;
        if(leadingZero)
            ans += rec(j+1,false,true);
        for(int i=0; i<digit.size();i++){
            if(digit[i]<=limit){
                bool newTight = (isTight && digit[i]==limit);
                ans += rec(j+1,newTight,false);
            }
        }
        return dp[j][isTight][leadingZero] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int ans =0;
        int x = n;
        for(string d:digits){
            digit.push_back(d[0]-'0');
        }
        while(x>0){
            num.push_back(x%10);
            x/=10;
        }
        this->n = num.size();
        reverse(num.begin(),num.end());
        memset(dp,-1,sizeof(dp));
        return rec(0,1,1); 
        
    }
};