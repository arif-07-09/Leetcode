class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0,y=0,ans=0;
        set<vector<int>>s;
        vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
        int k=0;
        for(auto &i:obstacles) s.insert(i);
        for(auto &i:commands){
            if(i==-1){
                k=(k+1)%4;
                continue;
            }
            else if(i==-2){
                k=(k+3)%4;
                continue;
            }
            else{
                int cmd=i;
                while(cmd--){
                    int X=x+directions[k][0];
                    int Y=y+directions[k][1];
                    if(s.count({X,Y})) break;
                    x=X;
                    y=Y;
                    ans=max(ans,x*x+y*y);
                }
            }
        }
        return ans;
    }
};