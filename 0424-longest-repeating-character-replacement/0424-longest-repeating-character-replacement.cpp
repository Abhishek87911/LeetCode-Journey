class Solution {
public:
    int isValid(vector<int> &freq,int k)
    {
        int totalFreq=0;
        int maxFreq=0;
        for(int i=0;i<26;i++)
        {
            maxFreq=max(maxFreq,freq[i]);
            totalFreq+=freq[i];
        }
        return totalFreq-maxFreq<=k;
    
    }
    int characterReplacement(string s, int k) {
        int n = s.length();
        int res=0;
        int j=0;
        vector<int> freq(26,0);
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'A']++;
            while(j<=i and !isValid(freq,k)){
                freq[s[j]-'A']--;
                j++;
            }
            res=max(res,i-j+1);

        }
        return res;
    }
};