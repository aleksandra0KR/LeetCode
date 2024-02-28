func minSubArrayLen(target int, nums []int) int {
    sum := 0
    left := 0
    right := 0
    numsLenght := len(nums)
    resLenght := 1000001
        
    for  right < numsLenght {
            
        if sum < target {
            sum += nums[right]
            right++
                
        } else{
            resLenght = min(resLenght, right - left);
            sum -= nums[left]
            left++
        }
            
    }
        for  sum >= target {
            resLenght = min(resLenght, right - left)
            sum -= nums[left]
            left++
        }
        
    if(resLenght == 1000001) {
        return 0
    }
    return resLenght
}