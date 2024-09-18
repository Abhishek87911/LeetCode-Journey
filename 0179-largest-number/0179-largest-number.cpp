class Solution {
public:
    static bool mycmp(int x,int y)
    {
       string s = to_string(x);
       string t = to_string(y);
      return s+t>t+s;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),mycmp);
        string res="";
        if(nums[0]==0) return "0";
        for(int i=0;i<nums.size();i++) res+=to_string(nums[i]);
        return res;
    }
};