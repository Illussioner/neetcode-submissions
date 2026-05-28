class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()<2) return nums;
        for(int gap = n/2; gap>=1; gap/=2){
            for(int i = gap; i<n; i++){
                int temp = nums[i];
                int j = i - gap;
                while(j >=0 && nums[j] > temp){
                    nums[j+gap] = nums[j];
                    j-=gap;
                    nums[j+gap] = temp;
                }
            }
        }
        return nums;
    }
};