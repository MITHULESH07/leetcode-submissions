class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans;
        stack<char>st;
         for(char c : seq){
            if(c=='('){
            ans.push_back(st.size()%2);
                st.push(c);
            }
            else{
                st.pop(); 
            ans.push_back(st.size()%2);
            }
         }

         return ans;
    }
};