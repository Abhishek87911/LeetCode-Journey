class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans= 0;
        set<pair<int,int>> st;
        for(auto o:obstacles) st.insert({o[0],o[1]});
        int dir = 0;
        int x = 0, y =0;
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]>0){
                int k = commands[i];
                while(k>0){
                    if(dir==0) {
                        y++;
                        if(st.find({x,y})!=st.end()){
                            
                            y--;
                            
                            break;
                        }
                    }
                    else if(dir==1) {
                        x--;
                            if(st.find({x,y})!=st.end()){
                               
                            x++;

                            break;
                        }
                    }
                    else if(dir==2) {
                        y--;
                        if(st.find({x,y})!=st.end()){
                            
                            y++;
                            break;
                        }
                    }
                    else {
                        x++;
                            if(st.find({x,y})!=st.end()){
                               
                            x--;
                            break;
                        }
                    }
                    k--;
                    ans=max(ans,abs(x)*abs(x)+abs(y)*abs(y));
                }

            }
            else if(commands[i]==-2){
                
                dir = (dir+1)%4;
                
            }
            else if(commands[i]==-1) dir = (dir-1+4)%4;
        }
        return ans;

    }
};