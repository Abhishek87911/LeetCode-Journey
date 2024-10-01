class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> freq(k);
        //if a%k == x and b%k == k-x then (a+b)%k==0
        for(int i=0;i<n;i++){
            freq[((arr[i]%k)+k)%k]++;
        }
        int l=1,h=k-1;
        if(freq[0]%2!=0) return false;
        while(l<h)
        {
            if(freq[l]!=freq[h]) return false;
            l++;
            h--;
        }
        return true;
    }
};