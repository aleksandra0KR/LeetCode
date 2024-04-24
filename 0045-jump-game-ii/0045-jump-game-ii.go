func jump(nums []int) int {
    for i:= 1; i < len(nums); i++{
        if nums[i - 1] > nums[i] + i {
            nums[i] =  nums[i-1]
        } else {
            nums[i] =  nums[i] + i
        }
    }
    
    result := 0
    position := 0
    for position < len(nums) - 1 {
        result++
        position = nums[position]
    }
    
    return result
}