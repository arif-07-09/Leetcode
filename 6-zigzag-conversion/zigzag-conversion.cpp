class Solution {
public:
    string convert(string s, int n) {
        if(n==1) return s;
        bool t=true;
        map<int,string>mp;
        int k=0;
        for(int i=0;i<s.size();i++){
            if(k==0) t=true;
            if(k==n-1) t=false;
            mp[k]+=s[i];
            if(t) k++;
            else k--;
        }
        string ans="";
        for(auto &i:mp){
            cout<<i.second<<endl;
            ans+=i.second;
        }
        return ans;
    }
};