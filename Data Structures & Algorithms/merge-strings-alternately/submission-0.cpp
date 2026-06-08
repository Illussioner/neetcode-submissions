class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int p1 , p2 = 0;
        while(p1<word1.length() && p2<word2.length()){
            res += word1[p1++];
            res += word2[p2++];
        }
        while(p1<word1.length()){
            res+= word1[p1++];
            
        }
        while(p2<word2.length()){
            res+= word2[p2++];
        }
        return res;
    }
};