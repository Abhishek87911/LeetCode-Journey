class Solution {
public:
    long long dp[101][101][101];
    long long fn(int i,int j,int n,int m,vector<int>& robot, vector<vector<int>>& factory,int cur_limit)
    {
        if(i>=n) return 0;
        if(j>=m) return 1e18;
        long long choice1 = 1e18;
        long long choice2 = 1e18;
        if(dp[i][j][cur_limit]!=-1) return dp[i][j][cur_limit];
        if(cur_limit>0){
            choice1 = abs(robot[i]-factory[j][0])+fn(i+1,j,n,m,robot,factory,cur_limit-1);
        }
        else choice1 = fn(i,j+1,n,m,robot,factory,factory[j+1][1]);

        choice2 = fn(i,j+1,n,m,robot,factory,factory[j+1][1]);
        return dp[i][j][cur_limit]=min(choice1,choice2);

    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        memset(dp,-1,sizeof(dp));
        int n = robot.size();
        int m = factory.size();
        factory.push_back({-1,-1});
        return fn(0,0,n,m,robot,factory,factory[0][1]);
    }
};