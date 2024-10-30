class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis1(n),lis2(n);
        vector<int> temp;
        lis1[0]=1;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            auto itr = lower_bound(begin(temp),end(temp),nums[i]);
            if(itr==temp.end()) {
                temp.push_back(nums[i]);
                lis1[i]=temp.size();
            }
            else {
                int idx = itr-temp.begin();
                temp[idx]=nums[i];
                lis1[i] = idx+1;
            }
            
            
        }
        temp.clear();
        lis2[n-1]=1;
        temp.push_back(nums[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            auto itr = lower_bound(begin(temp),end(temp),nums[i]);
            if(itr==temp.end()) {
                temp.push_back(nums[i]);
                lis2[i]=temp.size();
            }
            else {
                int idx = itr-temp.begin();
                temp[idx]=nums[i];
                lis2[i] = idx+1;
            }
           
            
        }
        int res=0;
        for(int i=1;i<=n-2;i++)
        {
            if(lis1[i]>1 and lis2[i]>1)
            res=max(res,lis1[i]+lis2[i]-1);
        }
        return n-res;
    }
};