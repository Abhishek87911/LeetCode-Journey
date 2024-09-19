class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        int n = exp.length();
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(exp[i]=='-' or exp[i]=='+' or exp[i] == '*'){
                vector<int> left_res = diffWaysToCompute(exp.substr(0,i));
                vector<int> right_res = diffWaysToCompute(exp.substr(i+1));
                for(auto x: left_res){
                    for(auto y: right_res){
                        if(exp[i]=='-'){
                            res.push_back(x-y);
                        }
                        else if(exp[i]=='+') res.push_back(x+y);
                        else res.push_back(x*y);
                    }
                }
            }
        }
        if(res.empty()) {
            res.push_back(stoi(exp));
            return res;
        }
        return res;
    }
};