class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right = numbers.size() - 1;
        
    for (int left = 0; left < numbers.size(); left++) {
        while (numbers[right] + numbers[left] > target) {
            right--;
        }
        if (numbers[right] + numbers[left] == target){
             return {left + 1, right + 1};
        }
    }
        
    return {};
        
    }
};