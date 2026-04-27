class Solution {
    map<int,string>mp;
    vector<vector<bool>>vis;
    bool check(char &a,char &b){
        return (a=='l' && b=='r') || (a=='r' && b=='l') ||
               (a=='u' && b=='b') || (a=='b' && b=='u');
    }
    bool solve(vector<vector<int>>& grid,int i,int j){
        int m=grid.size(),n=grid[0].size();
        if(i==m-1 && j==n-1) return true;
        if(i<0 || i>=m || j<0 || j>=n) return false;
        if(vis[i][j]) return false;
        vis[i][j]=true;
        // string cur_step=mp[grid[i][j]];
        // int k=0;
        // for(char dir : cur_step){
        //     int ni=i, nj=j;
        //     if(dir=='l') nj--;
        //     else if(dir=='r') nj++;
        //     else if(dir=='u') ni--;
        //     else if(dir=='b') ni++;

        //     if(ni<0 || ni>=m || nj<0 || nj>=n) continue;

        //     string next = mp[grid[ni][nj]];

        //     for(char back : next){
        //         if(check(dir, back)){
        //             if(solve(grid, ni, nj)) return true;
        //         }
        //     }
        // }
        // return false;
        string cur_step=mp[grid[i][j]];
        for(auto &dir:cur_step){
            int ni=i,nj=j;
            if(dir=='l') nj--;
            else if(dir=='r') nj++;
            else if(dir=='u') ni--;
            else if(dir=='b') ni++;
            if(ni<0 || ni>=m || nj<0 || nj>=n) continue;
            string next=mp[grid[ni][nj]];
            for(char back:next){
                if(check(dir,back)){
                    if(solve(grid, ni, nj)) return true;
                }
            }
        }
        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        mp[1]="lr";
        mp[2]="ub";
        mp[3]="lb";
        mp[4]="rb";
        mp[5]="lu";
        mp[6]="ru";
        int m=grid.size(),n=grid[0].size();
        vis.assign(m, vector<bool>(n,false));
        return solve(grid,0,0);
    }
};