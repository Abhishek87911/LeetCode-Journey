class Solution {
public:
    int res=0;
    int dfs(int x,int y,int rr,vector<vector<int>>& grid,vector<vector<int>> &dp)
    {
         int n = grid.size();
        int m = grid[0].size(); 
        if(dp[x][y]!=-1){
            res=max(res,dp[x][y]);
            return dp[x][y];
        } 
        
        res=max(res,rr);

      int dx[] ={0,1,-1};
      int dy[] = {1,1,1};
      for(int k =0;k<3;k++)
      {
          int nx = x+dx[k];
          int ny = y+dy[k];
          if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]>grid[x][y])
          {
               dp[nx][ny]=dfs(nx,ny,rr+1,grid,dp);
              
          }
         
         
           
      }
      return res;
     
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
       
        
        for(int i=0;i<n;i++)
        {
           
            dfs(i,0,0,grid,dp);

        }
        return res;
    }
};