class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        //keep a decreasing stack first , then traverse from last and observe things
        int n = nums.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty() or nums[st.top()]>nums[i]) st.push(i);

        }
        int res=0;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and nums[st.top()]<=nums[i]){
                res=max(res,i-st.top());
                st.pop();
            }

        }
        return res;
    }
};