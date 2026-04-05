class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int k=nums[i];
            if(mp[target-k]>0) return {i,mp[target-k]-1};
            mp[k]=i+1;
        }
        return {};
    }
};