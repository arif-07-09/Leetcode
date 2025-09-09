class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod=1e9+7;
        map<int,long>mp;
        for(int i=0;i<=n;i++) mp[i]=0;
        mp[1]=1;
        long ans=0;
        for(int i=2;i<=n;i++){
            if(i-delay>0) ans=(ans+mp[i-delay]+mod)%mod;
            if(i-forget>0) ans=(ans-mp[i-forget]+mod)%mod;
            mp[i]=ans;
        }
        ans=0;
        for(int i=n-forget+1;i<=n;i++) ans=(ans+mp[i])%mod;
        return (int)ans;
    }
};