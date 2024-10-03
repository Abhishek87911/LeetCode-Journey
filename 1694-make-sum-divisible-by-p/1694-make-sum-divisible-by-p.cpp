class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        //Just Like minimum length subarray with given sum
        int n = nums.size();
        int r=0;
        for(auto x: nums) r = (x+r)%p;
        if(r==0) return 0;
        int pr = 0;
        map<int,int> mp;
        mp[0]=-1;
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            pr = (pr+nums[i])%p;
            if(mp.find((pr-r+p)%p)!=mp.end())
            {
                ans=min(ans,i-mp[(pr-r+p)%p]);
            }
            mp[pr]=i;
        }
        return ans>=n?-1:ans;
    }
};