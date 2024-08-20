class Solution {
public:
    int findTheLongestSubstring(string s) {
        //represent a,e,i,o,u in bitmask 0--even freq and 1--odd freq
        //find the longest substring having bitmask as zero (standard question)
        int n = s.length();
        int bitmask = 0;
        map<int,int> mp;
        
        int ans=0;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u')
                     {bitmask = bitmask ^ (1<<(s[i]-'a'));}
            if(mp.find(bitmask)!=mp.end())
            {
                ans = max(ans,i-mp[bitmask]);
            }
            if(mp.find(bitmask)==mp.end()) mp[bitmask] = i;
        }
        return ans;


    }
};