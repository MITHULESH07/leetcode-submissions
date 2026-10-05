class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int ans = 0;
        for(char c: s){
            if(c == '('){
                st.push(-1);
            }else{
                int sum = 0;
                while(st.top() != -1){
                    sum += st.top();
                    st.pop();
                }
                st.pop();
                sum = (sum==0)?1:sum*2;
                st.push(sum);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};