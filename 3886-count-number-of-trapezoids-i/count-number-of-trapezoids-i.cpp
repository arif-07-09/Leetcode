class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,int>mp;
        int mod=1e9+7;
        long long ans=0,sum=0;
        for(auto &i:points){
            mp[i[1]]++;
        }
        for(auto &i:mp){
            long long edges=(long long)(i.second)*(i.second-1)/2;
            ans+=edges*sum;
            sum+=edges;
        }
        return ans%mod;
    }
};