class Solution {
public:
    string ans;
    set<string>res;
    int opened,closed;
    void rec(string & s, int i,int open,int removed_op,int removed_cl){
        if(i==s.length()){
            if(open==0)
                res.insert(ans);
            return;
        }
        if(open < 0 || opened < removed_op || closed < removed_cl)return;
        if(s[i] == ')'){
            rec(s,i+1,open,removed_op,removed_cl+1);
            ans.push_back(')');
            rec(s,i+1,open-1,removed_op,removed_cl);
            ans.pop_back();
        }
        else if(s[i]=='('){
            rec(s,i+1,open,removed_op+1,removed_cl);
            ans.push_back('(');
            rec(s,i+1,open+1,removed_op,removed_cl);
            ans.pop_back();
        }
        else{
            ans.push_back(s[i]);
            rec(s,i+1,open,removed_op,removed_cl);
            ans.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        stack<char>st;
        for(char c : s){
            if(c=='('){
                st.push('(');
            }
            else if(c == ')'){
                if(st.size())
                    st.pop();
                else
                    closed++;
            }
        }
        opened = st.size();
        cout<<opened<<closed;
        rec(s,0,0,0,0);
        vector<string> result;
        for(string str : res){
            result.push_back(str);
        }
        return result;
    }
};