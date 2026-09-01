class Solution {
public:
    bool closeStrings(string word1, string word2) {
       int freq1[26] = {0},freq2[26] = {0};
        for(char c: word1){
            freq1[c-'a']++;
        }
        for(char c:word2){
            freq2[c-'a']++;
        }
        for(int i = 0;i<26;i++){
            if((freq1[i] >0 && freq2[i] == 0) || (freq1[i] == 0 && freq2[i] > 0))return false;
        }
        for(int i = 0;i <26;i++){
            if(freq1[i] == 0)continue;
            bool assigned = false;
            for(int j = 0;j < 26;j++){
                if(freq1[i] == freq2[j]){
                    freq2[j] = 0;
                    assigned = true;
                    break;
                }
            }
            if(!assigned)return false;
        }
        return true;
    }
};