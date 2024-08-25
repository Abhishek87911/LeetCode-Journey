class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSmall(n,0);
        vector<int> rightSmall(n,0);
        int mod = 1e9+7;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and nums[st.top()]>=nums[i]) st.pop();
            leftSmall[i] = st.empty()?0:st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and nums[st.top()]>=nums[i]) st.pop();
            rightSmall[i] = st.empty()?n-1:st.top()-1;
            st.push(i);
        }

        vector<long long> pref(n+1);
        for(int i=1;i<=n;i++) pref[i]=pref[i-1]+nums[i-1];
        long long res = 0;
        // for(int i=0;i<n;i++) cout<<rightSmall[i]<<" "<<leftSmall[i]<<endl;
        for(int i=0;i<n;i++)
        {
            res = max(res,nums[i]*(pref[rightSmall[i]+1]-pref[leftSmall[i]]));
        }
        return res%mod;
    }
};