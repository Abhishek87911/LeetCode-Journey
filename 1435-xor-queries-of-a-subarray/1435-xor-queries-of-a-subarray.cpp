class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = arr.size();
        for(int i=1;i<n;i++) arr[i]^=arr[i-1];
        for(auto q: queries){
            int l = q[0];
            int r = q[1];
            int res = (l==0?arr[r]:arr[r]^arr[l-1]);
            ans.push_back(res);
        }
        return ans;
    }
};