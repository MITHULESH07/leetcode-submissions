class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for(int i = y1;i<=y2;i++){
            int j = x1;
            int dist = sqrt(((j-xCenter)*(j-xCenter)*1.00)+((i-yCenter)*(i-yCenter)*1.00));
            if(dist <= radius)return true;
            j = x2;
            dist = sqrt(((j-xCenter)*(j-xCenter)*1.00)+((i-yCenter)*(i-yCenter)*1.00));
            if(dist <= radius)return true;
        }
        for(int j = x1;j<=x2;j++){
            int i = y1;
            int dist = sqrt(((j-xCenter)*(j-xCenter)*1.00)+((i-yCenter)*(i-yCenter)*1.00));
            if(dist <= radius)return true;
            i = y2;
            dist = sqrt(((j-xCenter)*(j-xCenter)*1.00)+((i-yCenter)*(i-yCenter)*1.00));
            if(dist <= radius)return true;
        }
        if(x1 <= xCenter && xCenter <= x2 && y1 <= yCenter && yCenter <= y2 )return true;
        return false;
    }
};