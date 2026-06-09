class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // sorting helps us to repeatedly check for
        // the already checked first and second number
        unordered_map<int,int> count;
        for(int num : nums){
            count[num]++;
        }

        vector<vector<int>> res;
        for(int i = 0; i<nums.size(); i++){
            count[nums[i]]--;
            // one may wonder why we did this here couldn't
            // we do this after the continue
            // but we are working on a range like thing
            // that is triplet possible from the element
            // at that index i
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j<nums.size(); j++){
                count[nums[j]]--;
                if(j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int target = -(nums[i]+nums[j]);
                if(count[target]>0){
                    res.push_back({nums[i],nums[j],target});
                }
            }
            for(int j = i+1; j<nums.size(); j++){
                count[nums[j]]++;
            }

        }
        return res;
    }
};
