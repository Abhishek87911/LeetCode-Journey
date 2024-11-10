class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> freq(32,0);
        
        int res=INT_MAX;

        int j=0;
        int orr=0;
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int k=0;k<32;k++){
                if(((1<<k)&nums[i])){
                    freq[k]++;
                    
                    
                }

            }
            

            for(int k=0;k<32;k++){
                if(freq[k]) temp+=(1<<k);
            }
            orr = temp;
            while(j<=i and orr>=m){
                res=min(res,i-j+1);
                int r=0;
                for(int k=0;k<32;k++){
                    if((1<<k)&(nums[j])) freq[k]--;
                }
                for(int k=0;k<32;k++){
                    if(freq[k]) r+=(1<<k);
                }
                orr=r;
                j++;




            }
            
            

        }

        return res==INT_MAX?-1:res;
    }
};