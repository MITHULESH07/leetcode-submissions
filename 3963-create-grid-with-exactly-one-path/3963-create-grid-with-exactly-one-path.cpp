class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        for(int i = 0;i < m;i++){
            if(i < m-1){
                string res = ".";
                for(int j = 0;j < n-1;j++){
                    res+="#";
                }
                ans.push_back(res);
            }
            else{
                string res="";
                for(int j = 0;j < n;j++){
                    res+=".";    
                }
                ans.push_back(res);
            }
        }
        return ans;
    }
};