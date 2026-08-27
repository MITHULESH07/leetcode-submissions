class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n),ans;
        prefix[0] = arr[0];
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1]^arr[i];
        }
        for(vector<int> &q:queries){
            int l = q[0], r = q[1];
            if(l==r){
                ans.push_back(arr[r]);
            }
            else if(l==0){
                ans.push_back(prefix[r]);
            }
            else{
                ans.push_back(prefix[l-1]^prefix[r]);
            }
        }
        return ans;
    }
};