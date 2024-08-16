class Solution {
public:
    int uniqueLetterString(string s) {
        

        int n = s.length();
        vector<int> charEndingAti(26,-1);
        vector<int> prevIndOfCharEndingAti(26,-1);
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(charEndingAti[s[i]-'A']!=-1) {
                prevIndOfCharEndingAti[s[i]-'A']=charEndingAti[s[i]-'A'];
                charEndingAti[s[i]-'A']=i;

            }
            else charEndingAti[s[i]-'A']=i;

            for(char a='A';a<='Z';a++)
            {
                if(charEndingAti[a-'A']!=-1) {
                    res = res+1+(charEndingAti[a-'A']-(prevIndOfCharEndingAti[a-'A']==-1?0:prevIndOfCharEndingAti[a-'A']+1));
                }
            }
        }
        return res;
    }
};