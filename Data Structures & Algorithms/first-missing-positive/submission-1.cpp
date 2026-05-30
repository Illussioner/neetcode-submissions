class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n,false);
        for(int num: nums){
            if(num > 0 && num <=n){ // this is for the case
            // when there are no non positive numbers
                seen[num-1] = true;
            }
        }
        for(int i = 0; i<n; i++){
            if(!seen[i]) {
                return i+1;
            }
        }

        return n+1; // occurs when the array starts from 1 
        // there is no missing number or the missing num
        // the largest number-1
    }
};