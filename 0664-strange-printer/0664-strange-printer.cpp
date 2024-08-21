class Solution {
public:
    int n;
    int fn(int l,int r,string &s,vector<vector<int>> &dp)
    {
        if(l==r) return 1;
        if(l>r) return 0;
        int i=l+1;
        while(i<=r and s[i]==s[l]){
            i++;
        }
        if(i==r+1) return 1;
        if(dp[l][r]!=-1) return dp[l][r];
        int basic_appr = 1+fn(i,r,s,dp);
        int lalach_appr = INT_MAX;
        for(int j=i;j<=r;j++)
        {
            if(s[j]==s[l])
            lalach_appr = min(lalach_appr,fn(i,j,s,dp)+fn(j+1,r,s,dp));
        }
        return dp[l][r]=min(basic_appr,lalach_appr);
    }
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return fn(0,n-1,s,dp);
        
    }
};