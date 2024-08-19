class Solution {
public:
    int fn(int i,int n,int l, vector<vector<int>> &dp)
    {
        if(i>n) return 1e9;
        if(i==n) return 0;
        if(dp[i][l]!=-1) return dp[i][l];
        int copy = 2+fn(i+i,n,i,dp);
        int paste = 1+fn(i+l,n,l,dp);
        return dp[i][l]=min(copy,paste);
    }
    int minSteps(int n) {
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        int x = fn(1,n,1,dp);

        return n==1?0:1+x;
    }
};