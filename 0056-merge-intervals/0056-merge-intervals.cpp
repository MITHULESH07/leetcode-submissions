class Solution {
public:
    void sorting(vector<vector<int>>& intervals){
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a , const vector<int> &b){
            if(a[0]==b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sorting(intervals);
        vector<vector<int>>ans;
        int st = intervals[0][0],end = intervals[0][1];  
        for(vector<int> inv : intervals ){
            int newSt = inv[0], newEnd = inv[1];
            if(newSt <= end){
                end = max(newEnd,end);
            }
            else{
                ans.push_back({st,end});
                st = newSt;
                end = newEnd;
            }
        }
        ans.push_back({st,end});
        return ans;
    }
};