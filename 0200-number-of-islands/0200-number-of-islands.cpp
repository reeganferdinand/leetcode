class Solution {
public:
    void dfs(int src,int j,vector<vector<char>>& adj,vector<vector<int>>& vis,int n,int m)
    {
        vis[src][j]=1;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nr=src+dr[i];
            int nc=j+dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && adj[nr][nc]=='1' && !vis[nr][nc])
            {
                dfs(nr,nc,adj,vis,n,m);
            }
        }


    }
   
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    ans++;
                    //vis[i][j]=1;
                    dfs(i,j,grid,vis,n,m);
                }
            }
        }

        return ans;
    }
};