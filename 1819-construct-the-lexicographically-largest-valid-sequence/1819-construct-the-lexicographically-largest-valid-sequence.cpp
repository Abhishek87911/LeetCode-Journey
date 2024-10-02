class Solution {
public:
    vector<int> vis;
    bool fn(vector<int>& ans,int i)
    {
        if(i==ans.size()) return true;

        if(ans[i]) return fn(ans,i+1);
        for(int j=vis.size()-1;j>0;j--)
        {
            if(vis[j]) continue;
            if(j!=1 and (i+j>=ans.size() or ans[i+j])) continue;
            vis[j]=1;
            ans[i]=j;
            if(j!=1) ans[i+j]=j;
            if(fn(ans,i+1)) return true;
            vis[j]=0;
            ans[i]=0;
            if(j!=1) ans[i+j]=0;

        }
    return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1,0);
        vis.resize(n+1,0);
        fn(ans,0);
        return ans;
    }
};