class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(const int& num: nums){
            count[num]++;
        }

        vector<int> res;
        for(const auto& pair : count){
            if(pair.second > nums.size() / 3){
                res.push_back(pair.first);
            }
        }
        return res;
    }
};