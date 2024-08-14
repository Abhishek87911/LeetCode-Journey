class Solution {
public:
    int chk(int diff,vector<int>& nums, int k)
    {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            int indx = upper_bound(nums.begin(),nums.end(),nums[i]+diff)-nums.begin();
            
           
            cnt+=(indx-i-1);

        }
        return cnt<k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        // use binary search on answers 
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0, h = nums[n-1]-nums[0];
        int ans = -1;
        while(l<h)
        {
            int mid = (l+h)/2;
            if(chk(mid,nums,k))
            {
                
                l = mid+1;
            }
            else h = mid;

        }
        return l;
    }
};