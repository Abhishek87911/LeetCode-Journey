class Solution {
public:
    int hd = 0;
    bool check(int m,vector<vector<int>> &posEdges,vector<vector<int>> &negEdges,int s,int d,int t,int n)
    {
        vector<pair<int,int>> adj[n];
        for(auto e: posEdges) {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});

        }
        for(int i=0;i<=m;i++) {
            auto e=negEdges[i];
            adj[e[0]].push_back({e[1],-e[2]});
            adj[e[1]].push_back({e[0],-e[2]});

        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        vector<int> dist(n,2e9);
        dist[s]=0;
        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            int node = t.second;
            int dis = t.first;
            for(auto adjNode: adj[node])
            {
                if(dist[adjNode.first]>dis+adjNode.second)
                {
                    dist[adjNode.first]=dis+adjNode.second;
                    pq.push({dist[adjNode.first],adjNode.first});
                }
            }

        }
        if(dist[d]<=t){
           hd = dist[d];
           return true;
        }
        return false;
    }
    int initialCheck(int n,vector<vector<int>>& edges, int s, int d, int t)
    {
        vector<pair<int,int>> adj[n];
        for(auto e: edges) {
            if(e[2]>0)
            {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
            }
            else {
            adj[e[0]].push_back({e[1],1e9+1});
            adj[e[1]].push_back({e[0],1e9+1});
            }


        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        vector<int> dist(n,2e9);
        dist[s]=0;
        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            int node = t.second;
            int dis = t.first;
            for(auto adjNode: adj[node])
            {
                if(dist[adjNode.first]>dis+adjNode.second)
                {
                    dist[adjNode.first]=dis+adjNode.second;
                    pq.push({dist[adjNode.first],adjNode.first});
                }
            }

        }
        
        return dist[d];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<int>> posEdges,negEdges;
        bool conatinNegEdges=false;
        for(auto e: edges)
        {
            if(e[2]>0) posEdges.push_back(e);
            else {
                negEdges.push_back(e);
                conatinNegEdges=true;
            }
        }
        if(initialCheck(n,edges,source,destination,target)<target) return {};
        
        int l = 0, r = negEdges.size()-1;
        int ind= -1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(check(mid,posEdges,negEdges,source,destination,target,n)) {
                ind=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        // cout<<ind<<" "<<initialCheck(n,edges,source,destination,target)<<" "<<noNegEdges<<endl;
        if(!conatinNegEdges and initialCheck(n,edges,source,destination,target)==target) return edges;
        if(ind==-1) return {};
        for(int i=0;i<ind;i++) {
            negEdges[i][2]=1;
        } 
        negEdges[ind][2] = (target-hd+1);
        for(int i=ind+1;i<negEdges.size();i++) negEdges[i][2]=1000000009+1;
        vector<vector<int>> ans;
        for(auto x: posEdges) ans.push_back(x);
        for(auto x: negEdges) ans.push_back(x);
        return ans;



    }
};