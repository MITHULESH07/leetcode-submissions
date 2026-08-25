class Solution {
public:
    bool static check(const vector<int>&a,const vector<int>&b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),check);
        int n = people.size();
        vector<vector<int>>ans;
        int last = 0;
        for(int i = 0;i<n;i++){
            ans.insert(ans.begin()+people[i][1],people[i]);
        }
        return ans;
    }
};