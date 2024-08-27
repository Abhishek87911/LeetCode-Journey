class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<double,int>> adj[n+1];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});

        }

        vector<double> prob(n,0.0);
        prob[start_node]=1;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start_node});
        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            double p = x.first;
            int currNode = x.second;
            for(auto x: adj[currNode])
            {
                if(p*x.first>prob[x.second])
                {
                   prob[x.second] = p*x.first;
                   pq.push({prob[x.second],x.second});
                }
            }
        }
        return prob[end_node];



    }
};