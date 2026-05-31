class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] < 0){
                nums[i] = 0;
            }
        }

        for(int i = 0; i<n; i++){
            int val = abs(nums[i]); // this is 
            // if we mark some entry negative to mark
            // some other entry presence we ned the original
            // value of the entry marked negative
            if(val >=1 && val <=n){
                if(nums[val-1] > 0){
                    nums[val-1] *= -1;
                }
                else if (nums[val-1] == 0){
                    nums[val - 1] = -1 * ( n+1);
                    // we may wonder why is n+1 taken
                    // because from 1-> n is checked
                    // if we take anything different
                    // we may mark an element that is
                    // actually not present as some negative
                    // take is abs value and make the index
                    // value-1 as negative --> problems
                }
            }
        }
        for(int i = 1; i<=n; i++){
            if(nums[i-1] >=0) {
                return i;
            }
        }

        return n+1;
    }
};