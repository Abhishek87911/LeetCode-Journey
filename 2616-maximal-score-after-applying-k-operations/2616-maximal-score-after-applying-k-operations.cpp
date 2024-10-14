class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq(nums.begin(),nums.end());
        long long sum=0;
        while(k--)
        {
            long long x = pq.top();
            pq.pop();
            sum+=x;
            x=ceil(x/3.0);
            pq.push(x);
        }
        return sum;
    }
};