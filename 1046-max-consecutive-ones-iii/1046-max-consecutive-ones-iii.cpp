class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res=0;
        for(int i=0;i<n;i++) nums[i] = (nums[i]==0?1:0);
        int j=0; 
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=(nums[i]==1);
            while(cnt>k and j<=i){
                cnt-=(nums[j]==1);
                j++;
            }
            res=max(res,i-j+1);
        }
        return res;
    }
};