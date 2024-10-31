class Solution {
public:
    vector<int> fn(int n,vector<int>& a)
    {
        vector<int> t;
        for(int i=0;i<(1<<n);i++)
        {
            int sum = 0;
            for(int j=0;j<a.size();j++)
            {
                if(i&(1<<j)) sum+=a[j];
            }
            t.push_back(sum);

        }
        return t;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        //meet in  middle technique
        int n = nums.size();
        vector<int> arr1,arr2;
        for(int i=0;i<n;i++)
        {
            if(i<n/2) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        int p = n/2;
        int q = n-p;
        vector<int> allSunSetSum1 = fn(p,arr1);
        vector<int> allSunSetSum2 = fn(q,arr2);
        sort(begin(allSunSetSum2),end(allSunSetSum2));
        int ans = 1e9;
        for(int i=0;i<allSunSetSum1.size();i++)
        {
            int r = goal - allSunSetSum1[i];
            
            auto itr = lower_bound(begin(allSunSetSum2),end(allSunSetSum2),r);
            if(itr!=allSunSetSum2.end())
            ans = min(ans,abs(goal-(allSunSetSum1[i]+*itr)));
            if(itr!=allSunSetSum2.begin()) {
                itr--;
                ans = min(ans,abs(goal-(allSunSetSum1[i]+*itr)));
            }

        }
        return ans;


    }
};