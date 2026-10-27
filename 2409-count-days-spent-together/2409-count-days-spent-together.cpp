class Solution {
public:
    vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int convertToDays(string date){
        date[0]-='0';
        date[1]-='0';
        date[3]-='0';
        date[4]-='0';
        
        int mm = (date[0]*10)+date[1];
        int dd = (date[3]*10)+date[4];
        mm--;
        // cout<<date<<endl;
        // cout<<dd<<" "<<mm<<endl;
        int mon = 0;
        for(int i = 0; i < mm;i++){
            mon += month[i];
        }
        return dd+mon;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceArrive= convertToDays(arriveAlice);
        int bobArrive= convertToDays(arriveBob);
        int aliceLeave= convertToDays(leaveAlice);
        int bobLeave= convertToDays(leaveBob);
        int ans = min(aliceLeave,bobLeave)-max(aliceArrive,bobArrive);
        return ans>=0 ? ans+1 : 0;
    }
};