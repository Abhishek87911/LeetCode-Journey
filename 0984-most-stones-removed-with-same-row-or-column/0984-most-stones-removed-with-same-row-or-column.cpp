class DSU {
    public:
    vector<int> parent,size;
    DSU(int n)
    {
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i;
        size.resize(n+1,1);
    }
    int findUPar(int u)
    {
        if(parent[u]==u) return u;
        return parent[u] = findUPar(parent[u]);
    }
    void merge(int u,int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]) swap(pu,pv);
        size[pu]+=size[pv];
        parent[pv]=pu;
    }
};
class Solution {
public:

    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0,maxCol=0;
        for(auto it: stones)
        {
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        DSU dsu(maxRow+maxCol+1);
        map<int,int> mp;
        for(auto it: stones)
        {
            dsu.merge(it[0],it[1]+maxRow+1);
            mp[it[0]]=1;
            mp[it[1]+maxRow+1]=1;
        }
        int cnt=0;
        for(auto it: mp){
            if(dsu.findUPar(it.first)==it.first) cnt++;
        }
        return stones.size()-cnt;



    }
};