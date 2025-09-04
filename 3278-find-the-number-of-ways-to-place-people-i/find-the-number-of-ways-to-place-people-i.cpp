class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size(); // Total number of points
        for(int i=0;i<n;i++){
            int x1=points[i][0],y1=points[i][1]; //Current Rectangle bottom right corner 
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x2=points[j][0],y2=points[j][1]; //Points to be checked weather they are  upper left side or not
                if(x1>x2 || y1<y2) continue;
                bool t=true;
                for(int k=0;k<n;k++){ //To check weather any points lie between A & B
                    if(i==k || j==k) continue;
                    int x=points[k][0],y=points[k][1];
                    if(x>=x1 && x<=x2 && y<=y1 && y>=y2){ // point existing inside rectangle
                        t=false;
                        break;
                    }
                }
                if(t) ans++;
            }
        }
        return ans;
    }
};