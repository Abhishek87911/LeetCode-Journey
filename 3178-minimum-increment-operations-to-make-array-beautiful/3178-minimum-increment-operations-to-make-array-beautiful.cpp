class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        //dp[i] -- minimum no of moves to make arr0--i valid;
        
        
        int n = nums.size();
        vector<long long> dp(n);
        dp[0] = max(k-nums[0],0);
        dp[1] = max(k-nums[1],0);
        dp[2] = max(k-nums[2],0);
        for(int i=3;i<n;i++){
            dp[i] = max(k-nums[i],0)+min({dp[i-1],dp[i-2],dp[i-3]});

        }
        return min({dp[n-1],dp[n-2],dp[n-3]});

    }
};