class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        stack<char>st;
        queue<char>rev;
        for(char c : s){
            if(c==')'){
                while(st.top()!='('){
                    rev.push(st.top());
                    st.pop();
                }st.pop();
                while(!rev.empty()){
                    st.push(rev.front());
                    rev.pop();
                }
            }
            else{
                st.push(c);
            }
        }
        while(!st.empty()){
            if(st.top()!='(')
                ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};