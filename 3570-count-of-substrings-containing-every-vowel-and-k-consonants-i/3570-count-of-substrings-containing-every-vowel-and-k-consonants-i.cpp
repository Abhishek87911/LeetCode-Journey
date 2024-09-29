class Solution {
public:
    long long fn(string word, int k)
    {
        int n = word.length();
        long long res=0;
        int a=0,e=0,ii=0,o=0,u=0;
        int j=0;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(word[i]=='a') a++;
            else if(word[i]=='e') e++;
            else if(word[i]=='i') ii++;
            else if(word[i]=='o') o++;
            else if(word[i]=='u') u++;
            else c++;
            while(j<=i  and a>=1 and e>=1 and ii>=1 and o>=1 and u>=1 and c>=k){
                res+=(n-i);
            if(word[j]=='a') a--;
            else if(word[j]=='e') e--;
            else if(word[j]=='i') ii--;
            else if(word[j]=='o') o--;
            else if(word[j]=='u') u--;
            else c--;
            j++;
            }
            

        }
        return res;
    }
    long long countOfSubstrings(string word, int k) {
        return fn(word,k)-(fn(word,k+1));
    }
};