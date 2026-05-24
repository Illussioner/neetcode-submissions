class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            while(start<nums.size() && nums[start]!=val){
                start++;
            }
            while(end>=0 && nums[end]==val){
                end--;
            }
            if(start < end){
                swap(nums[start],nums[end]);
            }
        }
        return start;
    }
};