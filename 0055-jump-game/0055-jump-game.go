func canJump(nums []int) bool {
    var maxPosition int = 0
     var length int = len(nums) - 1

    
    for i:= 0; i <= length; i++ {
        if maxPosition >= length {
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