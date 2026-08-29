class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>Groups = nums;
        sort(Groups.begin(),Groups.end());
        unordered_map<int,vector<int>>Group;
        unordered_map<int,int>Belong;
        unordered_map<int,int>MinInd;
        int id = 1;
        Belong[Groups[0]] = id;
        Group[id].push_back(Groups[0]);
        for(int i = 1;i<n;i++){
            if(Groups[i]-Groups[i-1]>limit){
                id++;
            }
            Group[id].push_back(Groups[i]);
            Belong[Groups[i]] = id;
        }
        for(int i = 1;i<id;i++){
            MinInd[i] = 0;
        }
        for(int i = 0;i < n;i++){
            id = Belong[nums[i]];
            nums[i] = Group[id][MinInd[id]]; 
            MinInd[id]++;
        }
        return nums;
    }
};