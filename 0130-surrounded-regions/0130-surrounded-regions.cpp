class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();


        vector<vector<bool>> can(n,vector<bool>(m,true));

        queue<pair<int,int>> q;

        // rows
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                can[i][0]=false;
                q.push({i,0});
            }

            if(board[i][m-1]=='O')
            {
                can[i][m-1]=false;
                q.push({i,m-1});
            }

        }

        // colums

        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O')
            {
                can[0][i]=false;
                q.push({0,i});
            }

            if(board[n-1][i]=='O')
            {
                can[n-1][i]=false;
                q.push({n-1,i});
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();


            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]=='O'&& can[nr][nc])
                {
                    can[nr][nc]=false;
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(can[i][j]==true)
                {
                    board[i][j]='X';
                }
            }
        }


    }
};