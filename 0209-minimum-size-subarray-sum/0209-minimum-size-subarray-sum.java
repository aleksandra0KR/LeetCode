class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        Integer sum = 0;
        Integer left = 0;
        Integer right = 0;
        Integer numsLenght = nums.length;
        Integer resLenght = 1000000;
        
        while(right < numsLenght){
            
            if(sum < target){
                sum += nums[right];
                right++;
                
            }
            
            else{
                resLenght = Math.min(resLenght, right - left);
                sum -= nums[left];
                left++;
            }
            
        }
        while(sum >= target){
            resLenght = Math.min(resLenght, right - left);
            sum -= nums[left];
            left ++;
        }
        
        if(resLenght == 1000000) return 0;
        return resLenght;
    }
}