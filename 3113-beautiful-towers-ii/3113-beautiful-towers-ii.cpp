class Solution {
public:
    long long maximumSumOfHeights(vector<int>& mH) {
        int n = mH.size();
        vector<int> leftSmall(n,0),rightSmall(n,0);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and mH[st.top()]>mH[i]) st.pop();
            leftSmall[i] = (st.empty()?-1:st.top());
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and mH[st.top()]>mH[i]) st.pop();
            rightSmall[i] = (st.empty()?n+1:st.top());
            st.push(i);
        }

        vector<long long> left(n,0),right(n,0);
        for(int i=0;i<n;i++)
        {
            if(leftSmall[i]==-1){
                left[i] = (i+1)*1ll*mH[i]*1ll;
            }
            else left[i] = (i-leftSmall[i])*1LL*mH[i]+left[leftSmall[i]];
        }
        for(int i=n-1;i>=0;i--)
        {
            if(rightSmall[i]==n+1){
                right[i] = (n-i)*1ll*mH[i]*1ll;
            }
            else right[i] = (rightSmall[i]-i)*1LL*mH[i]*1LL+right[rightSmall[i]];
        }

        long long res = 0;
        for(int i=0;i<n;i++)
        {
            res=max(res,left[i]+right[i]-mH[i]);
        }
        return res;


    }
};