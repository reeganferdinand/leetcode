class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();

        int fresh=0;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    fresh++;

                else if(grid[i][j]==2)
                    q.push({i,j});
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        int ans=0;

        while(!q.empty())
        {
            int size=q.size();
            bool changed=false;

            for(int i=0;i<size;i++)
            {
                auto it=q.front();
                q.pop();

                int r=it.first;
                int c=it.second;

                for(int k=0;k<4;k++)
                {
                    int nr=r+dr[k];
                    int nc=c+dc[k];

                    if(nr>=0 && nr<n &&
                       nc>=0 && nc<m &&
                       grid[nr][nc]==1)
                    {
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        fresh--;
                        changed=true;
                    }
                }
            }

            if(changed)
                ans++;
        }

        if(fresh==0)
            return ans;

        return -1;
    }
};