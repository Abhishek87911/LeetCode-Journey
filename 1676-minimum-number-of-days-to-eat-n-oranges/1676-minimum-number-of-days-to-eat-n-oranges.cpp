class Solution {
public:
    
    int fn(int i,unordered_map<int,int>& dp)
    {
        if(i==0) return 0;
        if(i==1) return 1;
        if(dp.find(i)!=dp.end()) return dp[i];
        
        return dp[i] = 1+min(i%2+fn(i/2,dp),i%3+fn(i/3,dp));
    }
    int minDays(int n) {
        
        // vector<long long> dp(n+1,-1);
        unordered_map<int,int> dp;
        return (int)fn(n,dp);
        // dp[0]=0;
        // dp[1]=1;
        // for(int i=2;i<=n;i++)
        // {
            
        //     dp[i] = dp[i-1]+1;
        //     if(i%2==0) dp[i] = min(dp[i],dp[i/2]+1);
        //     if(i%3==0) dp[i]=min(dp[i],dp[i/3]+1);
            
        // }
        // return dp[n];

        
        
       
    }
};