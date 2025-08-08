class Solution {
    string solve(string s,int i,int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
public:
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            string odd=solve(s,i,i);
            string even=solve(s,i,i+1);
            if(odd.size()>ans.size()) ans=odd;
            if(even.size()>ans.size()) ans=even;
        }
        return ans;
    }
};