class Solution {
public:
    long fn(long fh,bool isEven)
    {
        long resNum = fh;
        if(!isEven)
        {
            fh/=10;

        }
        while(fh>0) {
            int digit = fh%10;
            resNum = (resNum*10)+digit;
            fh/=10;
        }
        return resNum;
    }
    string nearestPalindromic(string s) {
        int n = s.length();
        int mid = n/2;
        int fhl = (n%2==0)?mid:mid+1;
        long fh = stol(s.substr(0,fhl));
        vector<long> posRes;
        posRes.push_back(fn(fh,n%2==0));
        posRes.push_back(fn(fh+1,n%2==0));
        posRes.push_back(fn(fh-1,n%2==0));
        posRes.push_back(powl(10,n-1)-1);
        posRes.push_back(powl(10,n)+1);


        long diff = LONG_MAX;
        long res = INT_MAX;
        long org = stol(s);

        for(long num: posRes)
        {
            if(num ==  org) continue;
            if(abs(num-org)<diff)
            {
                diff = abs(num-org);
                res=num;
            } else if(abs(num-org)==diff){
                res = min(res,num);
            }
        }
        return to_string(res);



    }
};