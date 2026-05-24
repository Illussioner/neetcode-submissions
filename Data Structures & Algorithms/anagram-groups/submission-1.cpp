class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> count(26,0);
        unordered_map<string, vector<string>> res;
        for(const auto& s : strs){
            for(char c: s){
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for(int i=1; i<26; i++){
                key+=','+to_string(count[i]);
            }
            res[key].push_back(s);
            fill(count.begin(),count.end(), 0);
        }
        vector<vector<string>> result;
        for(const auto& pair: res){
            result.push_back(pair.second);
        }
        return result;
    }
};
