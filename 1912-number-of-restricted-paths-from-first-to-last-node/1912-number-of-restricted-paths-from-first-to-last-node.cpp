
class Solution {
public:
    vector<long long> djk(int n,vector<pair<int,int>> adj[],int src)
    {
        vector<long long> dist(n,1e18);
        dist[src]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,src});
        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            long long dis = t.first;
            int node = t.second;
            if(dis!=dist[node]) continue;
            for(auto x: adj[node]){
                int adjNode = x.second;
                long long wt = x.first;
                if(dist[adjNode]>wt+dis){
                        dist[adjNode]=wt+dis;
                        pq.push({dist[adjNode],adjNode});
                }
            }

        }
        
        return dist;

    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<long long> dis(n);
        int mod=1e9+7;
        vector<pair<int,int>> adj[n];
        for(auto e: edges){
            adj[e[0]-1].push_back({e[2],e[1]-1});
            adj[e[1]-1].push_back({e[2],e[0]-1});

        }
        dis = djk(n,adj,n-1);
        vector<int> adj2[n];
        for(auto e: edges){
            int u = e[0]-1;
            int v = e[1]-1;
            if(dis[u]<dis[v]) adj2[u].push_back(v);
            else if(dis[v]<dis[u]) adj2[v].push_back(u);

        }   
        vector<long long> idg(n,0);
        
        for(int i=0;i<n;i++){
                for(auto v: adj2[i]) idg[v]++;
        }
       
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(idg[i]==0) q.push(i);
        }
        for(auto x: idg) cout<<x<<" ";
        vector<int> ans(n,0);
        ans[n-1]+=1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto v: adj2[u]){
                idg[v]--;
                if(idg[v]==0) q.push(v);
                ans[v]=(ans[u]+ans[v])%mod;
            }
        }
             return ans[0];


    }
};