class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int left=0;
        map<char,int>mp;
        for(int right=0;right<s.size();right++){
            char c=s[right];
            if(mp.find(c)!=mp.end() && mp[c]>=left){
                left=mp[c]+1;
            }
            ans=max(ans,right-left+1);
            mp[c]=right;
        }
        return ans;
    }
};