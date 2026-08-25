class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans ="";
        if(k==num.size())return "0";
        stack<char>st;
        for(char c:num){
            while(k>0 && !st.empty() && st.top()>c){
                st.pop();
                k--;
            }
            if(st.empty() && c=='0')continue;
            st.push(c);
        }
        while(k && !st.empty()){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0)ans="0";
        return ans;
    }
};