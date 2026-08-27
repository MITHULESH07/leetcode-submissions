class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        vector<int>bit(n,0);
        for(int i = 0; i < n;i++){
            for(int j = 0;j < words[i].length();j++){
                bit[i] = bit[i] | 1 << (words[i][j]-'a');
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                int x = words[i].length();
                int y = words[j].length();
                int len = x+y;
                if((bit[i] & bit[j]) ==0){
                    ans = max(ans, x*y);
                }
            }
        }
        return ans;
    }
};