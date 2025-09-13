class Solution {
public:
    int maxFreqSum(string s) {
        int mo=0,mc=0;
        map<char,int>mp; // To store the count of the each character
        set<char>c={'a','e','i','o','u'};
        for(auto &i:s){
            mp[i]++;
            if(c.count(i)){
                if(mp[i]>mo){
                    mo=mp[i];
                }
            }else{
                if(mp[i]>mc){
                    mc=mp[i];
                }
            }
        }
        return mo+mc;
    }
};