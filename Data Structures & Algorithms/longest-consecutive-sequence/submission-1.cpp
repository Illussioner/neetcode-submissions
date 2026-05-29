class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        sort(nums.begin(),nums.end());
        int res = 0;
        int curr = nums[0];
        int i = 0;
        int streak = 0;
        while(i<n){
            if(curr != nums[i]){
                curr = nums[i];
                streak = 0;
            }
            while(i<n && nums[i]==curr){
                i++;
            }
            streak++;
            curr++;
            res = max(res,streak);
        }
        return res;
    }
};
