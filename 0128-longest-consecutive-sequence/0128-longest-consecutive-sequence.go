func longestConsecutive(nums []int) int {
    if len(nums) < 1{
        return 0
    } else if len(nums) == 1{
        return 1
    } 
    
    sort.Ints(nums)
        
    maxConsequence := 0
    current := 0
        
    for i := 0; i < len(nums) - 1; i++ {
        if nums[i] == nums[i+1] - 1{
            current++
        } else if nums[i] == nums[i+1]{
            continue
        } else{
            maxConsequence = max(current, maxConsequence)
            current = 0
        }
    
    }
    
    maxConsequence = max(current, maxConsequence) + 1

        
    return maxConsequence
}
func max(a, b int) int{
    if a > b{
        return a
    }
    return b
}