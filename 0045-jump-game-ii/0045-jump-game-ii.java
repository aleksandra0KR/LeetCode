class Solution {
    public int jump(int[] nums) {
        for(int i = 1; i < nums.length; i++){
            nums[i] = Math.max(nums[i - 1], nums[i] + i);
        }
        
        int result = 0;
        int position = 0;
        
        while(position < nums.length - 1){
            result++;
            position = nums[position];
        }
        
        return result;
    }
}