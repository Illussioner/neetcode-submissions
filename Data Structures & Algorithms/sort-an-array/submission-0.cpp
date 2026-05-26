class Solution {
public:
int partition(vector<int>& nums,int left, int right){
    int mid = (left + right ) >> 1;
    swap(nums[mid], nums[left+1]);
    if(nums[left] > nums[right]){
        swap(nums[left],nums[right]);
    }
    if(nums[left+1] > nums[right]){
        swap(nums[left+1],nums[right]);
    }
    if(nums[left] > nums[left+1]){
        swap(nums[left],nums[left+1]);
    }
    int pivot = nums[left+1];
    int i = left+1;
    int j = right+1;
    while(true){
        while(i <= right-1 &&  nums[++i]<pivot);
        while(j >= left+1 && nums[--j]>pivot);
        if(i>=j) break;
        swap(nums[i],nums[j]);
    }
    nums[left+1] =nums[j];
    nums[j] = pivot;
    return j;
}
void quickSort(vector<int>& nums, int left, int right){
    if(left >= right) return;
    int j = partition(nums,left,right);
    quickSort(nums,left,j-1);
    quickSort(nums,j+1,right);
}
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() < 2) return nums;
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};