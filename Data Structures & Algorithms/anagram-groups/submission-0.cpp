class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort each and every string
        // sorted form of anagrams must match
        // based on the sorted string insert the original string
        // into the vector of string corresponding to that 
        // sorted string
        // finally key the sorted string and value will be a
        // vector of all the string that are anagrams
        unordered_map<string, vector<string>> res;
        for(const auto& s: strs){
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            res[sortedS].push_back(s);
        }
        vector<vector<string>> result;
        for(const auto& pair: res){
            result.push_back(pair.second);
        }
        return result;
    }
};
