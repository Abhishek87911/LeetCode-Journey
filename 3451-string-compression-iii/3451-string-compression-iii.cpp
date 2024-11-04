class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        int cnt=1;
        int i=1;
        string ans="";
        char c = word[0];
        while(i<n)
        {
            while(cnt<9 and word[i]==word[i-1]){
                i++;
                cnt++;
            }
            ans.push_back(char('0'+cnt));
            ans.push_back(c);
            if(i<n){
            c=word[i];
            cnt=1;
            }
            else c=' ';
            i++;
            
        }
         if(c!=' '){
             ans.push_back(char('0'+cnt));
         ans.push_back(c);
         }
        return ans;
        
    }
};