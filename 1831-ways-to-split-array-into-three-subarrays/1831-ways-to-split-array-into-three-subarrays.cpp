class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        int mod=1e9+7;
        for(int i=1;i<n;i++) nums[i]+=nums[i-1];
        set<int> st(begin(nums),end(nums));
        if(st.size()==1 and st.find(0)!=st.end()) {
            int res=0;
            for(int i=0;i<n-2;i++) res=(res+n-(i+2))%mod;
            return res;
        }
        vector<int> pref=nums;
        int res=0;
        for(int i=0;i<n-2;i++){
            int leftV = pref[i];
            int midIdx=-1;
            int l = i+1,h=n-1;
            while(l<=h)
            {
                int mid = (l+h)/2;
                if(pref[mid]-pref[i]>=leftV){
                    midIdx=mid;
                    h=mid-1;
                }
                else l=mid+1;

            }
            if(midIdx==-1 or midIdx==n-1) continue;
            int midV = pref[midIdx]-pref[i];
            int rightIdx=-1;
             l = midIdx+1;
             int r=n-1;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(pref[n-1]-pref[mid-1]>=midV){
                    rightIdx=mid;
                    l=mid+1;
                }
                else r=mid-1;

            }
            if(rightIdx==-1) continue;
            l = midIdx,r= rightIdx;
            int idx=-1;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(pref[mid]-pref[i]<=pref[n-1]-pref[mid]){
                    idx=mid;
                    l=mid+1;
                }
                else r=mid-1;
            }
            if(idx==-1) continue;
            cout<<i<<" "<<midIdx<<" "<<idx<<" "<<rightIdx<<endl;
            res=(res+((idx-midIdx)+1)%mod)%mod;



        }
        return res;
        
    }
};