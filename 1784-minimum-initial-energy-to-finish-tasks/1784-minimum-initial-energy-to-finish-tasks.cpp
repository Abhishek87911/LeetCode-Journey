class Solution {
public:

    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        sort(begin(tasks),end(tasks),[&](vector<int>& a1,vector<int>& a2){
            return (a1[1]-a1[0])>(a2[1]-a2[0]);
        });

        int ans =0 ;
        int currEnergy = 0;
        for(int i=0;i<n;i++)
        {
            if(currEnergy<tasks[i][1]){
                ans+=(tasks[i][1]-currEnergy);
                currEnergy+=(tasks[i][1]-currEnergy);
            }
            currEnergy-=tasks[i][0];
        }
        return ans;
    }
};