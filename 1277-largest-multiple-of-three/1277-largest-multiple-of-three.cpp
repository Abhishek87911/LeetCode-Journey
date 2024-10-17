class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        
        map<int,multiset<int>> mp;
        for(auto e: digits) {
            if(e%3==2) {
                mp[2].insert(e);
            }
            if(e%3==1) {
                mp[1].insert(e);
            }

        }

        int sum=0;
        for(auto e: digits) sum+=e;
        int r = sum%3;
        map<int,int> mp2;
        for(auto d: digits) mp2[d]++;
        string res="";
        


        
       
            if(r==1)
            {
                if(mp[1].size()>0) {
                    mp2[*(mp[1].begin())]--;
                }
                else if(mp[2].size()>1){
                    mp2[*(mp[2].begin())]--;
                    mp[2].erase(mp[2].find(*(mp[2].begin())));
                    mp2[*(mp[2].begin())]--;

                }
            }
            else if(r==2)
            {
                if(mp[2].size()>0) {
                    mp2[*(mp[2].begin())]--;
                }
                else if(mp[1].size()>1){
                    mp2[*(mp[1].begin())]--;
                    mp[1].erase(mp[1].find(*(mp[1].begin())));
                    mp2[*(mp[1].begin())]--;

                }
            }
            for(auto e=mp2.rbegin();e!=mp2.rend();e++)
            {
                int x = e->second;
                while(x>0 and x--)
                {
                    res+=to_string(e->first);
                }
            }
        

        reverse(begin(res),end(res));
        while(res.size()>1 and res.back()=='0') res.pop_back();
        reverse(begin(res),end(res));
        return res;

    }
};