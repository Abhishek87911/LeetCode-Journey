class Solution {
public:
    bool isPos=true;
    void dfs(int i,int j,vector<vector<int>>& grid2, vector<vector<int>>& grid1,vector<vector<int>> &vis)
    {
        int m = grid1.size();
        int n = grid1[0].size();
        int d4x[4] = {1,0,-1,0};
        int d4y[4] = {0,1,0,-1};
        if(grid1[i][j]==0) isPos=false;
        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int nx = i+d4x[k];
            int ny = j+d4y[k];
            if(nx>=0 and nx<m and ny>=0 and ny<n and !vis[nx][ny] and grid2[nx][ny]==1)
            {
                if(grid1[nx][ny]==0) isPos=false;
                dfs(nx,ny,grid2,grid1,vis);
            }
        }

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int res=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] and grid2[i][j]==1) {
                    isPos=true;
                    dfs(i,j,grid2,grid1,vis);
                    if(isPos) res++;
                }
            }
        }
        return res;


    }
};