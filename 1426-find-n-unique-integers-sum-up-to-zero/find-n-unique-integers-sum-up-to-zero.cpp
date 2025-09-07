class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        ans.push_back(0);
        for(int i=1;i<n;i++){
            ans.push_back(i);
            ans[0]=ans[0]-i;
        }
        return ans;
    }
};