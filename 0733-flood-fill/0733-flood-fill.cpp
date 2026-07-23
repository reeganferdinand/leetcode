class Solution {
public:
    
    void dfs(int r,int c,int clr,vector<vector<int>> &grid,vector<vector<int>>&vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        int org=grid[r][c];
        vis[r][c]=1;
        grid[r][c]=clr;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==org && !vis[nr][nc])
            {
                dfs(nr,nc,clr,grid,vis);
            }
        }
    }
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        if(image[sr][sc]==color) return image;

        vector<vector<int>>vis(n,vector<int>(m,0));
        dfs(sr,sc,color,image,vis);

        return image;

    }
};