class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end());
        int ans = 0;
        int r = 0;
        map<int,vector<int>>mp;
        for(vector<int>row:reservedSeats){
            mp[row[0]].push_back(row[1]);
        }
        for(auto m:mp){
            ans += (m.first-r-1)*2;
            r = m.first;
            bool a = true;
            bool b = true;
            bool c = true;
            bool d = true;
            for(int i:m.second){
                if(i==2 ||i==3)a =false;
                else if(i==4 || i==5 )b=false;
                else if(i==6 || i==7 )c=false;
                else if(i==8||i==9)d=false;
            } 
            if(a && b && c && d){ans+=2;}
            else if((a && b)||(c && d)||(b && c)){ans+=1;}
        }   
        if(r<n)
            ans+=(n-r)*2;
        return ans;
    }
};