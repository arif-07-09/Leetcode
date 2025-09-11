class Solution {
    bool check(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        vector<int>v;
        for(auto &i:s){
            if(check(i)) v.push_back(i);
        }
        int j=v.size()-1;
        for(auto &i:s){
            if(check(i)){
                i=v[j];
                j--;
            }
        }
        return s;
    }
};