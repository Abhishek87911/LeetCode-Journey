class Solution {
public:
    int dp[301][302];
    int fn(int i,int j,vector<int>& nums, vector<int>& mult)
    {   int n = nums.size();
        if(i+j>mult.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int c1 = mult[i+j-1]*nums[i]+fn(i+1,j,nums,mult);
        int c2 = mult[i+j-1]*nums[n-j]+fn(i,j+1,nums,mult);
        
        return dp[i][j]=max(c1,c2);

    }
    int maximumScore(vector<int>& nums, vector<int>& mult) {
        memset(dp,-1,sizeof(dp));
        return fn(0,1,nums,mult);
    }
};