class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        if(grid.size()==0) return 0;
        
        int r=grid.size();
        int c=grid[0].size();

        //total oranges
        int tot=0;

        //rotten oranges
        int cnt=0;


        // totl time 

        int time=0;

        // queue for rotten oranges

        queue<pair<int,int>> q;

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]!=0)
                {
                    tot++;
                }

                if(grid[i][j]==2) 
                {
                    q.push({i,j});
                }
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty())
        {
            int k=q.size();

            cnt+=k;

            while(k--)
            {
                int rr=q.front().first;
                int rc=q.front().second;

                q.pop();

                for(int i=0;i<4;i++)
                {
                    int nr=rr+dr[i];
                    int nc=rc+dc[i];

                    if(nr<0 || nr>=r || nc<0 || nc>=c || grid[nr][nc]!=1) continue;

                    grid[nr][nc]=2;

                    q.push({nr,nc});
                }
            }

            if(!q.empty())
            {
                time++;
            }
        }

        return tot==cnt? time:-1;
    }
};