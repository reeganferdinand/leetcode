class Solution {
public:
    
    
    void dfs(int r,int c,vector<vector<int>> &image ,vector<vector<int>> &vis,int color,int src)
    {
        vis[r][c]=1;
        image[r][c]=color;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nr<image.size() && nc>=0 && nr<image[0].size() && image[nr][nc]==src && !vis[nr][nc])
            {
                dfs(nr,nc,image,vis,color,src);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        dfs(sr,sc,image,vis,color,image[sr][sc]);

        return image;


    }
};