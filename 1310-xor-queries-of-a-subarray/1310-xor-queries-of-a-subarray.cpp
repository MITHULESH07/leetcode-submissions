class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix,ans;
        int xr = 0;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            xr = xr^arr[i];
            prefix.push_back(xr);
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