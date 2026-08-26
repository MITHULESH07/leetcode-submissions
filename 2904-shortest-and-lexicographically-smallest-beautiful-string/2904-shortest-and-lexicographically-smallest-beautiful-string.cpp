class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int n = s.length(), minLen = INT_MAX;
        int l = 0 , count = 0;
        for(int r = 0;r < n;r++){
            if(s[r] == '1')count++;
            while(count > k||(count == k && s[l]=='0')){
                if(s[l]=='1')count--;
                l++;
            }
            if(count==k){
                int len = r-l+1;
                if(len < minLen){
                    ans =s.substr(l,len);
                    minLen = len;
                }
                else if(len == minLen){
                    bool valid = false;
                    for(int i = 0;i < len;i++){
                        if(s[l+i]>ans[i]){
                            break;
                        }
                        else if(s[l+i]<ans[i]){
                            valid = true;
                            break;
                        }
                    }
                    if(valid){
                        ans = s.substr(l,len);
                    }
                }
            }
        }
        return ans;
    }
};