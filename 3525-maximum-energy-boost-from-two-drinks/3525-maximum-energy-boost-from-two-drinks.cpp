class Solution {
public:
    long long dp[100001][3];
    long long fn(int i,vector<int>& a, vector<int>& b,int c)
    {
        if(i==a.size()) return 0;
        long long c1 = 0, c2 = 0;
        if(dp[i][c+1]!=-1) return dp[i][c+1];
        if(c==-1)
        {
            c1 = a[i]+fn(i+1,a,b,0);
            c2 = b[i]+fn(i+1,a,b,1);
        }
        else if(c==1)
        {
             c1 = fn(i+1,a,b,0);
            c2 = b[i]+fn(i+1,a,b,1);
        }
        else {
             c1 = a[i]+fn(i+1,a,b,0);
            c2 =fn(i+1,a,b,1);
        }
        return dp[i][c+1]=max(c1,c2);
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        memset(dp,-1,sizeof(dp));
        return fn(0,energyDrinkA,energyDrinkB,-1);
    }
};