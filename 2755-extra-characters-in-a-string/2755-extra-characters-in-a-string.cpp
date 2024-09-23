class Solution {
public:
    int fn(int i, unordered_set<string> &st,string s, vector<int> &dp)
    {
        if(i>=s.size()) return 0;
        if(st.find(s)!=st.end()) return 0;
        if(dp[i]!=-1) return dp[i];
        int op = 1e9;
        for(int k=i;k<s.size();k++)
        {
            if(st.find(s.substr(i,k-i+1))!=st.end())  op = min(op,fn(k+1,st,s,dp));
           
        }
        return dp[i]=min(op,1+fn(i+1,st,s,dp));
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        vector<int> dp(s.length()+1,-1);
        return fn(0,st,s,dp);
    }
};