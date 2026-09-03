class Solution {
public:
    int n;
    vector<vector<string>>ans;
    vector<string> part;
    bool isPalindrome(string s){
        for(int i = 0; i < s.length()/2; i++){
            if(s[i] != s[s.length()-i-1])return false;
        }
        return true;
    }
    void rec(string s,int i){
        if(i==n){
            ans.push_back(part);
            return;
        }
        for(int j = i+1; j <= n;j++){
            string newCurr = s.substr(i,j-i);
            if(isPalindrome(newCurr)){
                part.push_back(newCurr);
                rec(s,j);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        rec(s,0);
        return ans;
    }
};