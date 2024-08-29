class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>> time(n,vector<int>(m,1e9));
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
       time[0][0] = grid[0][0];
       pq.push({time[0][0],{0,0}});
       int d4x[4] = {1,0,-1,0};
       int d4y[4] = {0,1,0,-1};
       while(!pq.empty())
       {
         auto t = pq.top();
         pq.pop();
         int ox = t.second.first;
         int oy = t.second.second;
         int tim = t.first;
         if(tim!=time[ox][oy]) continue;
         for(int k=0;k<4;k++)
         {
            int nx = ox+d4x[k];
            int ny = oy+d4y[k];
            if(nx>=0 and nx<n and ny>=0 and ny<m)
            {
                if(time[nx][ny]>tim+(max(grid[nx][ny]-tim,0))) {
                    time[nx][ny]=tim+(max(grid[nx][ny]-tim,0));
                    pq.push({time[nx][ny],{nx,ny}});
                }
            }
         }

         
       }

        return time[n-1][m-1];
    }
};