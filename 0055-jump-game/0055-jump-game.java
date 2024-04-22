class Solution {
    public boolean canJump(int[] nums) {
        int maxPosition = 0;
        
        for(int i = 0; i < nums.length; i++){
            if(maxPosition >= nums.length - 1) return true;
            if(nums[i] == 0 && maxPosition == i) return false;
            if(nums[i] + i > maxPosition) maxPosition = nums[i] + i ;
        }
        
        return true;
    }
}