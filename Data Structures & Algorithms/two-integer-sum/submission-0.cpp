class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> ump;
        for(int i=0; i<n; i++){
            if(ump.find(target-nums[i])!=ump.end()){
                return {ump[target-nums[i]], i};
            }
            ump.insert({nums[i],i});
        }
        return {};
    }
};
