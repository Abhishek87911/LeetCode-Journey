class Solution {
public:
    int dp[35000];
    int fn(vector<int> adj[],int mask,int n,int k)
    {
        if(mask == ((1<<n)-1)) return 0;
        
        
        if(dp[mask]!=-1) return dp[mask];
        
        vector<int> indg(n);
        for(int i=0;i<n;i++) {
            if((mask&(1<<i))) continue;
            for(auto v: adj[i]) indg[v]++; 
        }

        int temp = 0;
        for(int i=0;i<n;i++)
        {
            if(indg[i]==0 and (!(mask&(1<<i)))) temp = temp | (1<<i);
        }
        int j = temp;
        int cnt = __builtin_popcount(j);
        int ans = 1e9;
        if(cnt>k)  // if no of indg nodes are more than k , we can take a subset of size k 
        {
            for(int i=j;i>0;i=(i-1)&temp)
            {
                cnt = __builtin_popcount(i);
                if(cnt!=k) continue;
                ans = min(ans,1+fn(adj,mask|i,n,k));
            } // generate all submask of a mask .. refer cp algo for more details
        }
        else // take all available zeo indg nodes
        {
            ans = min(ans,1+fn(adj,mask|j,n,k));
        }
        return dp[mask] = ans;

        



    }
    int minNumberOfSemesters(int n, vector<vector<int>>& rel, int k) {
        vector<int> adj[n];
        
        for(auto e: rel)
        {
            adj[e[0]-1].push_back(e[1]-1);
            

        }
        
        int mask = 0;
        memset(dp,-1,sizeof(dp));
        vector<int> vis(n);
        return fn(adj,mask,n,k);

        
    }
};