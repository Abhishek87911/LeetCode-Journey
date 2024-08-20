class Solution {
public:
    int res=0;
    int fn(vector<int>& piles,int m,int n,int i,int turn, vector<vector<vector<int>>> &dp)
    {
        if(i>=n) return 0;
        if(dp[turn][i][m]!=-1) return dp[turn][i][m];
        int res=turn==1?INT_MAX:-1;
        int temp=0;
        for(int in=1;in<=min(2*m,n-i);in++)
        {
          temp+=piles[i+in-1];
          if(turn==0){
              res=max(res,temp+fn(piles,max(m,in),n,i+in,1,dp));
          }
          else res=min(res,fn(piles,max(m,in),n,i+in,0,dp));
        }
       return dp[turn][i][m]=res;

    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        
        return fn(piles,1,n,0,0,dp);
    }
};