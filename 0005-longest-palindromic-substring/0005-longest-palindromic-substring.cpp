class Solution {
public:
    string expandAroundCenter(int l,int r,string &s,string &res){
        int n = s.length();
        while(l>=0 and r<n and s[l]==s[r]){
            l--;
            r++;
        } 
        l++;
        r--;
        string temp_res = s.substr(l,r-l+1);
        if(temp_res.length()>res.length()){
            res = temp_res;
        }
        return res;
    }
    string longestPalindrome(string s) {
    int n = s.length();
    string res = "";
    // odd length substring 
    for(int i=0;i<n;i++){
        int l = i-1,r = i+1;
        res = expandAroundCenter(l,r,s,res);
       
    }

    // even length substring

    for(int i=0;i<n-1;i++)
    {
        if(s[i]!=s[i+1]) continue;
        int l = i-1,r = i+2;
       
        res = expandAroundCenter(l,r,s,res);
    }
    return res;
    }
};