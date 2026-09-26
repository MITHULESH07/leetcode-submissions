class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans ="", word = "";
        unordered_map<string,string>know;
        bool braces = false;
        for(int i = 0; i < knowledge.size();i++){
            know[knowledge[i][0]] = knowledge[i][1]; 
        }
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                braces = true;
                continue;
            }
            if(s[i] == ')' && braces){
                braces = false;
                if(know.find(word)!=know.end())
                    ans += know[word];
                else 
                    ans += "?";
                word = "";
                continue;
            }
            if(braces){
                word += s[i];
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};