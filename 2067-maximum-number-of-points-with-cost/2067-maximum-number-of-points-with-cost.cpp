class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
    
        long long ans=0;
        int n = points.size();
        int m = points[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        for(int j=0;j<m;j++)
        {
            dp[0][j] = points[0][j]; 
        }

        for(int i=1;i<n;i++)
        {
            vector<long long> left_dp(m,-1),right_dp(m,-1);
            left_dp[0]=dp[i-1][0]+0;
            right_dp[m-1]=dp[i-1][m-1]-m+1;
            for(int j=1;j<m;j++){
                left_dp[j] = max(left_dp[j-1],dp[i-1][j]+j);
            }
            for(int j=m-2;j>=0;j--){
             
                right_dp[j] = max(right_dp[j+1],dp[i-1][j]-j);
            }
            for(int j=0;j<m;j++)
            {
                dp[i][j]=max(left_dp[j]-j,right_dp[j]+j)+points[i][j];
            }
        }
        return *max_element(dp[n-1].begin(),dp[n-1].end());
    }
};