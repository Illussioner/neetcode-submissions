class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int> temp(nums.begin(), nums.begin()+n-k);
        int i = 0; 
        while(i<k){
            nums[i] = nums[i+n-k];
            i++;
        }
        for(int i = 0; i <temp.size(); i++){
            nums[i+k] = temp[i];
        }
    }
};