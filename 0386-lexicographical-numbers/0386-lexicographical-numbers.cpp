class Solution {
public:
    vector<int> res;
    void fn(int i,int n)
    {
        res.push_back(i);
        for(int j=0;j<=9;j++){
            if(i*10+j>n) break;
            fn(i*10+j,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=9;i++){
            if(i>n) break;
            fn(i,n);
        }
        return res;
    }
};