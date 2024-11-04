class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs[0].length();
        for(int i=0;i<strs.size();i++)
        {
            n=min(n,(int)strs[i].length());
        }
        int i=0;
        string res="";
        while(i<n)
        {
            char ch = strs[0][i];
            for(int j=0;j<strs.size();j++)
            {
                if(strs[j][i]!=ch) return res;
            }
            res.push_back(ch);
            i++;
        }
        return res;

    }
};