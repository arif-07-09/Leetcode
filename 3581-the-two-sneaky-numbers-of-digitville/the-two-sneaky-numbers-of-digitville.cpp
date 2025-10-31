class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int ans=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                if(ans!=-1) return {ans,nums[i]};
                else ans=nums[i];
            }
        }
        return {};
    }
};