class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        int n = nums.size();
        vector<int> arr(n);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%mod==k) arr[i]=1;
            else arr[i]=0;
        }
        map<int,int> mp;
        
        int prefSum=0;
        long long res=0;
        for(int i=0;i<n;i++)
        {
            prefSum=(prefSum+arr[i]);
            int modV = prefSum%mod;
            if(modV == k) res++;
            int find = modV-k;
            if(find<0) find+=mod;
            res+=mp[find];
            mp[modV]++;

        }
        return res;

    }
};