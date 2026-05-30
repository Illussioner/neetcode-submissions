class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missing = 1;
        while(true) {
            bool flag = true; // true if not found yet
            for(const int& num: nums){
                if(missing == num) {
                    flag =false;
                    break;
                }
            }
            if(flag) return missing;
            missing++;
        }
    }
};