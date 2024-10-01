class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int maxi = -1;
            int ind=0;
            for(int i=0;i<n;i++) {
                if(maxi<mat[i][mid]){
                    ind=i;
                    maxi=mat[i][mid];
                }
            }
            bool isAns=true;
            if(mid-1>=0 and mat[ind][mid-1]>mat[ind][mid]) isAns=false;
            if(mid+1<m and mat[ind][mid+1]>mat[ind][mid]) isAns=false;
            if(isAns) return {ind,mid};
            if(mid-1>=0 and mat[ind][mid-1]>mat[ind][mid]) high=mid-1;
            else low=mid+1;


        }
        return {-1,-1};
    }
};