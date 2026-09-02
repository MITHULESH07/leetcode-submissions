class Trie {
public:
    vector<Trie*>arr;
    bool isEnd;
    vector<string>top_3;
    Trie(){
        arr.resize(26,NULL);
        isEnd = false;
    }
    void insert(string s, Trie* root){
        Trie* curr = root;
        for(char ch : s){
            int c = ch - 'a';
            if(curr->arr[c] == NULL){
                curr->arr[c] = new Trie();
            }
            curr = curr->arr[c];
            if(curr->top_3.size()<3){
                curr->top_3.push_back(s);
            }
        }
        curr->isEnd = true;
    }
    vector<vector<string>> find(string s, Trie* root){
        Trie* curr = root;
        vector<vector<string>> ans(s.length());
        for(int i = 0; i < s.length(); i++){
            int c = s[i] - 'a';
            if(curr->arr[c]== NULL){
                curr->arr[c] = new Trie();
            }
            curr = curr->arr[c];
            ans[i] = (curr->top_3);
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        Trie* root = new Trie();
        for(string s : products){
            root->insert(s,root);
        }
        return root->find(searchWord,root);      
    }
};