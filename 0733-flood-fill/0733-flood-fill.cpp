class Solution {
public:
    vector<int>dx= {-1,0,1,0};
    vector<int>dy= {0,-1,0,1};
    int n,m,c;
    void dfs(vector<vector<int>>&image,int i,int j,int oc){
        if(i<0||j<0||i>=n|j>=m||image[i][j]!=oc)return;
        image[i][j]=c;
        for(int k = 0;k<4;k++){
            dfs(image,i+dx[k],j+dy[k],oc);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oc = image[sr][sc];
        if(oc == color)return image;
        n = image.size(), m = image[0].size();
        c=color;
        dfs(image,sr,sc,oc);
        return image;
    }
};