class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int> freq(26,0),wind(26,0);
       int n = s1.length(),m = s2.length();
       if(n>m) return false;
       for(int i=0;i<n;i++) freq[s1[i]-'a']++;
       for(int i=0;i<n;i++) wind[s2[i]-'a']++;
       if(freq==wind) return true;
       for(int i=n;i<m;i++)
       {
           wind[s2[i-n]-'a']--;
           wind[s2[i]-'a']++;
            if(freq==wind) return true;

       }
       return false;

    }
};