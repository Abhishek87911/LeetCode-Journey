class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int prefixSum=0;
        mp[start]++;
             mp[end]--;
        for(auto &it: mp)
        {
              
            prefixSum+=it.second;
            if(prefixSum>1) {
                        mp[start]--;
                        mp[end]++;
                return false;
            }
        }
       
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */