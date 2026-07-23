class Solution {
public:
    

    void bfs(int src,int j,vector<vector<char>>&grid,vector<vector<int>>& vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({src,j});

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            vis[temp.first][temp.second]=1;
            for(int i=0;i<4;i++)
            {
                int nr=temp.first+dr[i];
                int nc=temp.second+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc])
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
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
                    bfs(i,j,grid,vis);
                }
            }
        }

        return ans;
    }
};