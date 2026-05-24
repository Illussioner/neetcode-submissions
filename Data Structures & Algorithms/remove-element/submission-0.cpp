class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k =count(nums.begin(),nums.end(),val);
        int n = nums.size();
        while(count(nums.begin(),nums.end(),val)){
            auto it =find(nums.begin(),nums.end(), val);
            nums.erase(it);
        }
        return n-k;
    }
};