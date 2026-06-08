class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(),l=0,r=0;
        while(r<n){
            nums[l] = nums[r];
            while(r<n && nums[r] == nums[l]){
                r++;
            }
            l++;
            // nums[l] = nums[r]; // here what is happening 
            // that I accesing memory at index n which is
            // not available to me 
        }
        return l;
    }
};