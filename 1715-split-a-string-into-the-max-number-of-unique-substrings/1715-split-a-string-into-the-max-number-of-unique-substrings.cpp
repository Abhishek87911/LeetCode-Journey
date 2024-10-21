class Solution {
public:
    int fn(int i,string s,unordered_set<string> &st)
    {
        if(i==s.length()) return 0;
        int op=0;
        for(int k=i;k<s.length();k++)
        {
            if(st.find(s.substr(i,k-i+1))==st.end()){
                st.insert(s.substr(i,k-i+1)) ;
                op=max(op,1+fn(k+1,s,st));
                st.erase(s.substr(i,k-i+1));

            }
        }
        return op;

    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return fn(0,s,st);
    }
};