#define ll long long
class Solution {
public:
    long long minEnd(int n, int x) {
        int i=0;
        map<int,ll> mp;
        for(int k=0;k<=63;k++){
            if((x&(1LL<<k))==0){
                mp[i]=(1LL<<k);
                i++;
            }
        }
       
        ll mask = n-1;
        ll res=x;
        for(int k=63;k>=0;k--){
            if((mask&(1LL<<k))){
                res=res+mp[k];
            }
        }
        return res;

    }
};