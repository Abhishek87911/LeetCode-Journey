class Solution {
public:
    bool rotateString(string s, string t) {
        if(s.length()!=t.length()) return false;
        string temp = s+s;
        if(temp.find(t)==string::npos) return false;
        return true;
    }
};