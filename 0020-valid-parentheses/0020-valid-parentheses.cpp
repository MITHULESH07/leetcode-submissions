class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c : s){
            if(c==')' || c==']' || c=='}'){
                if(!st.empty() && ((c==')' && st.top()=='(') || (c==']' && st.top()=='[') ||(c=='}' && st.top()=='{')))
                st.pop();
                else
                return false;
            }
            else{
                st.push(c);
            }
        }
        return st.empty();
    }
};