class Solution {
public:
    int n;
    void rec(int i,int j,vector<string>&ans, string & s){
        if(j == n){
            ans.push_back(s);
            return;
        }
        if(i < n){
            s.push_back('(');
            rec(i+1,j,ans,s);
            s.pop_back();
        }
        if(j < i){
            s.push_back(')');
            rec(i,j+1,ans,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        this->n = n;
        vector<string>ans;
        string s="";
        rec(0,0,ans,s); 
        return ans; 
    }
};