class Solution {
public:
    int minChanges(string s) {
        int res=0;
        int n = s.length();
        for(int i=1;i<n;i+=2)
        {
            if(s[i]!=s[i-1]) res++;
        }
        return res;
    }
};