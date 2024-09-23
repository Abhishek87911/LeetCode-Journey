class Solution {
public:
    int count(long long curr,long long next,int n)
    {
        int r= 0 ;
        while(curr<=n)
        {
            r+=(next-curr);
            curr*=10;
            next*=10;
            next=min(next,(long long)n+1);
        }
        return r;

    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k-=1;
        while(k>0)
        {
            int cnt = count(curr,curr+1,n);
            if(cnt<=k){
                curr++;
                k-=cnt;
            }
            else {
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};