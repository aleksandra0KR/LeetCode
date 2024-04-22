func canJump(nums []int) bool {
    
    maxPosition := 0

    for i:= 0; i < len(nums); i++ {
        if maxPosition >= len(nums) - 1 {
            return true
        }
        if nums[i] == 0 && maxPosition == i {
            return false;
        }
        if nums[i] + i > maxPosition {
            maxPosition = nums[i] + i
        }
    }
    
    return true
}