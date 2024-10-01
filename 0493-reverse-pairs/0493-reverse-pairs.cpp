class Solution {
public:
   int countPairs(vector<int>& nums, int low,int mid,int high)
   {
       int cnt=0;
      
       int right=mid+1;
       for(int i=low;i<=mid;i++){
           while(right<=high and (long long)nums[i]>(long long)nums[right]*2ll) right++;
           cnt+=(right-(mid+1));

       }
       return cnt;
   }
    int merge(vector<int>& nums, int low,int mid,int high)
    {

        vector<int> temp;
        int left=low;
        int right=mid+1;
        int cnt=0;
        cnt=countPairs(nums,low,mid,high);
        while(left<=mid and right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else {
                 temp.push_back(nums[right]);
                 right++;
                
                 
            }
        }
        while(left<=mid){
             temp.push_back(nums[left]);
                left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
                 right++;
        }
        for(int i=low;i<=high;i++) nums[i]=temp[i-low];
        return cnt;
    }
    int mergesort(vector<int>& nums, int low,int high)
    {
        if(low>=high) return 0;
        int cnt=0;
        int mid = (low+high)>>1;

        cnt+=mergesort(nums,low,mid);
        cnt+=mergesort(nums,mid+1,high);
        cnt+=merge(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(nums,0,n-1);
    }
};