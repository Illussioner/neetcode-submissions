class Solution {
private:
    void radixSort(vector<int>& arr){   
        int n = arr.size();
        if(n<2) return;
        int maxElement = *max_element(arr.begin(), arr.end());
        int d = 1;
        while(maxElement / d > 0){
            countSort(arr, n, d);
            d *= 10;
        }
    } 
    void countSort(vector<int>& arr, int n, int d) { 
        vector<int> count(10,0);
        for(int num : arr){
            count[(num/d)%10]++;
        }
        for(int i=1; i<10; i++){
            count[i]+=count[i-1];
        }
        vector<int> res(n);
        for(int i = n-1; i>=0; i--) { 
            int idx = (arr[i]/d)%10;
            res[count[idx]-1] = arr[i];
            count[idx]--;
        }
        for(int i = 0; i<n; i++){
            arr[i] = res[i];
        }
    } 
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> negatives, positives;
        for(int num: nums) {
            if(num <0) {
                negatives.push_back(-num);
            }
            else{
                positives.push_back(num);
            }
        }
        if(!negatives.empty()){
            radixSort(negatives);
            reverse(negatives.begin(), negatives.end());
            for(int &num : negatives) {
                num = -num;
            }
        }
        if(!positives.empty()){
            radixSort(positives);
        }
        int index = 0;
        for(const int& num: negatives) {
            nums[index++] = num;
        }
        for(const int& num: positives) {
            nums[index++] = num;
        }
        return nums;
    }
};