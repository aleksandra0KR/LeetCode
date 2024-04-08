class Solution {
    public int[] twoSum(int[] numbers, int target) {
       
        int right = numbers.length - 1;
        
        for (int left = 0; left < numbers.length; left++) {
            while (numbers[right] + numbers[left] > target) {
                right--;
            }
            if (numbers[right] + numbers[left] == target){
                int[] result = {left + 1, right + 1};
               return result;
            }
    }
        
    int[] result = {};
    return result;
        
    }
}