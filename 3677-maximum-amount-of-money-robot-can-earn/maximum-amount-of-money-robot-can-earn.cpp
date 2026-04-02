class Solution {
    int solve(vector<vector<int>>& coins, vector<vector<vector<int>>> &dp,int m, int n, int i, int j, int k){
        if(i<0 || i>=m || j<0 || j>=n) return INT_MIN;
        int val=coins[i][j];
        if(i==m-1 && j==n-1) return k>0 ? max(val,0) : val;
        if(dp[i][j][k]!=INT_MIN) return dp[i][j][k];
        int take=max(solve(coins,dp,m,n,i+1,j,k),solve(coins,dp,m,n,i,j+1,k));
        take+=val;
        int not_take=INT_MIN;
        if(k>0 && val<0){
            not_take=max(solve(coins,dp,m,n,i+1,j,k-1),solve(coins,dp,m,n,i,j+1,k-1));
        }
        return dp[i][j][k]=max(take,not_take); 
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        return solve(coins,dp,m,n,0,0,2);
    }
};