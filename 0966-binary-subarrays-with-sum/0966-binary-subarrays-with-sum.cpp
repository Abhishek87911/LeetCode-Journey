class Solution {
public:
    int fn(vector<int>& nums, int goal,int n)
    {
        int j=0;
        int res=0;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            curr+=nums[i];
            while(j<=i and curr>goal){
                curr-=nums[j];
                j++;
            }
            res+=(i-j+1);
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return fn(nums,goal,n)-fn(nums,goal-1,n);
        
    }
};