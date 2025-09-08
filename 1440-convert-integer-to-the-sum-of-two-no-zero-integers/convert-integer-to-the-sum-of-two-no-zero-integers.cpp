class Solution {
    bool check(int i){
        while(i){
            if(i%10==0) return false;
            i/=10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n/2;i++){
            if(check(i) && check(n-i)) return {i,n-i};
        }
        return {};
    }
};