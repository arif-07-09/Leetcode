class Solution {
    map<int,map<int,double>>dp;
    int m;
    double solve(int i,int j){
        if(i<=0 && j<=0) return 0.5;
        if(i<=0) return 1;
        if(j<=0) return 0;
        if(dp[i].count(j)) return dp[i][j];
        return dp[i][j]=(solve(i-4,j)+solve(i-3,j-1)+solve(i-2,j-2)+solve(i-1,j-3))/4;
    }
public:
    double soupServings(int n) {
        if(n>=4800) return 1;
        m=ceil(n/25.0);
        for(int k=1;k<=m;k++){
            if(solve(k,k)>1-1e-5) return 1;
        }
        return solve(m,m);
    }
};