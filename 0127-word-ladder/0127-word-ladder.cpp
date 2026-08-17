class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,bool>mp;
        int n = beginWord.size();
        mp[beginWord]=false;
        for(string s:wordList){mp[s]=true;}
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto [word,s] =q.front();
            q.pop();
            for(int i = 0;i<n;i++){
                char init = word[i];
                for(char c = 'a';c<='z';c++){
                    word[i] = c;
                    if(mp.find(word)!=mp.end() && mp[word]){
                        mp[word]=false;
                        if(word==endWord){
                            return s+1;
                        }
                        q.push({word,s+1});
                    }
                }
                word[i] = init;
            }
        }
        return 0;

    }
};