class MedianFinder {
public:
    priority_queue<int> l;
    priority_queue<int,vector<int>,greater<int>> u;
    MedianFinder() {
     //cout<<u.size()<<" "<<l.size()<<" ";
    }
    
    void addNum(int num) {
        if(l.empty()) l.push(num);
        else if(num>l.top()){
           
            u.push(num);
            if(u.size()>l.size())
            {
               
                
                int x = u.top();
                u.pop();
                l.push(x);
            }
        }
        else {
            l.push(num); 

            if(l.size()-u.size()>1){
                
                 int x = l.top();
                l.pop();
                u.push(x);
            }
        }
    }
    
    double findMedian() {
        if(l.size()>u.size()) return (double)l.top();
        else return (u.top()+l.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */