class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> res;
        int i = 0;
        while(i<n){
            int j = i+1;
            while(j<n && nums[i] == nums[j]){
                j++;
            }
            if(j-i > n/3){
                res.push_back(nums[i]);
            }
            i = j;
        }
        return res;
    }
};