class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        map<int,int> mp;
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++)
        {
            long double f = sqrt(nums[i]);
            
            if(floor(f)!=ceil(f)) {
               
                mp[nums[i]]=1;
            }
            else {
                
                if(mp.find(nums[i])!=mp.end()) continue;
                mp[nums[i]]+=mp[f]+1;
            }
            
        }
        for(auto x: mp) ans=max(ans,x.second);
        return ans==1?-1:ans;
    }
};