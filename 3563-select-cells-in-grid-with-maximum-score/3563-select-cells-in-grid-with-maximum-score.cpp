class Solution {
public:
    int dp[1200][101];
    int fn(vector<vector<int>> &a,int mask,int i,int n,int r)
    {
        // cout<<mask<<" ";
        if(mask==pow(2,r)-1) return 0;
        if(i>n) {
            return -1e9;
        }
        int ans = 0;
        if(dp[mask][i]!=-1) return dp[mask][i];
        ans = max(ans,fn(a,mask,i+1,n,r));
        for(int j=0;j<a[i].size();j++)
        {
            if((mask&(1<<a[i][j]))) continue;
            int newMask = mask|(1<<a[i][j]);
            ans=max(ans,i+fn(a,newMask,i+1,n,r));
        }
        return dp[mask][i]=ans;
    }
    int maxScore(vector<vector<int>>& grid) {
       vector<vector<int>> a(101);
       int n = grid.size();
       int m = grid[0].size();
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            a[grid[i][j]].push_back(i);
        }
       } 
    //    for(auto x: a){
    //     for(int i=0;i<x.size();i++) cout<<x[i]<<" ";
    //     cout<<endl;
    //    }

       int mask = 0;
       memset(dp,-1,sizeof(dp));
       return fn(a,mask,1,100,n);

    }
};