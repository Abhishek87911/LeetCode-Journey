class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> suff(n);
        suff[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            if(s[i]>s[suff[i+1]]){
                suff[i]=i;
            }
            else suff[i]=suff[i+1];
        }
        for(int i=0;i<n-1;i++){
            if(suff[i]!=i and s[suff[i+1]]!=s[i]) {
                swap(s[i],s[suff[i+1]]);
                return stoi(s);
            }
        }
        return stoi(s);
    }
};