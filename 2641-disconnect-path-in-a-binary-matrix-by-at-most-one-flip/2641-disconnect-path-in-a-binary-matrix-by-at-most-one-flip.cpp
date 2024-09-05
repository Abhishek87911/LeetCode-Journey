class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>& grid,int n,int m)
    {
        if(i==n-1 and j==m-1) return true;
        if(i>=n or j>=m or grid[i][j]==0) return false;
        grid[i][j]=0;
        return dfs(i+1,j,grid,n,m) or dfs(i,j+1,grid,n,m);
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool r = dfs(0,0,grid,n,m);
        if(!r) return true;
        grid[0][0]=1;
        return !dfs(0,0,grid,n,m);

    }
};