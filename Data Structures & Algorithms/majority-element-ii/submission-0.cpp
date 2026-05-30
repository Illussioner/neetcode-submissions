class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_set<int> res;
        int n = nums.size();
        for(const int& num : nums){
            int count = 0;
            for(const int& i : nums){
                if(i == num){
                    count++;
                }
            }
            if(count > n/3){
                res.insert(num);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};