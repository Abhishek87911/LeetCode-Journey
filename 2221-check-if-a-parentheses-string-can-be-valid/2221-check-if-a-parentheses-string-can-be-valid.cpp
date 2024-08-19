class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        int n = s.length();
        if(n%2) return false;
        int tot = 0, open=0,closed=0;
        
        for(int i=0;i<n;i++)
        {
            if(locked[i]=='0') tot++;
            else {
                if(s[i]=='(') open++;
                else closed++;
            }
            if(tot+open-closed<0){
                
               return false;
            } 
        }
        
        tot = 0, open=0,closed=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(locked[i]=='0') tot++;
            else {
                if(s[i]=='(') open++;
                else closed++;
            }
            if(tot-open+closed<0){
                return false;
            } 
        }
       return true;

    }
};