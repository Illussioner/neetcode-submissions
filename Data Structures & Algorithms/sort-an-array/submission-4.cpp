class Solution {
private:
    void countingSort(vector<int>& nums) {
        unordered_map<int,int> count;
        int minVal = *min_element(nums.begin(),nums.end());
        int maxVal = *max_element(nums.begin(),nums.end());

        for(auto& val : nums){
            count[val]++;
        }
        int index = 0;
        for(int i =minVal; i<=maxVal; i++){
            while(count[i]>0){
                nums[index]=i;
                index++;
                count[i]--;
            }
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        countingSort(nums);
        return nums;
    }
};