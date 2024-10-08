class Solution {
public:
    bool chk(int m,vector<int>&nums,int k)
    {
        int cnt = 0;
        int r=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>m) continue;
            else {
                r++;
                i++;
            }
        }
        cnt = max(cnt,r);
        r=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>m) continue;
            else {
                r++;
                i++;
            }
        }
        cnt = max(r,cnt);
        return cnt>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *min_element(begin(nums),end(nums));
        int high = *max_element(begin(nums),end(nums));
        int ans = 0;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(chk(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }
            else low = mid+1;

        }
        return ans;
    }
};