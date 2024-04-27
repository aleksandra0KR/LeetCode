class Solution {
public:
    int binarySearch(vector<int>& nums, int index){
        if(index - 1 >= 0 and nums[index - 1] > nums[index]) return binarySearch(nums, index - 1);
        if(index + 1 < nums.size() and nums[index + 1] > nums[index]) return binarySearch(nums, index + 1);
        return index;
    }
    
    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums, nums.size()/2);
    }
};