class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size()-1);
    }
private:
    void reverse(vector<char>& s, int l , int r){
        if(l<r){
            swap(s[l], s[r]);
            reverse(s, l+1, r-1);         
        }
    }
};