class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        int n = nums.size();
        for(int num: nums){
            count[num]++;
            if(count.size() > 2){
                for(auto it = count.begin();
                it != count.end();){
                    it->second--;
                    if(it->second == 0){
                        it = count.erase(it);
                    }
                    else{
                        ++it;
                    }   
                }
            }
        }
        vector<int> res;
        for(auto& entry :count){
            int frequency = 0;
            for(const int& num : nums){
                if(num==entry.first) frequency++;
            }
            if(frequency > n/ 3){
                res.push_back(entry.first);
            }
        }
        return res;
    }
};