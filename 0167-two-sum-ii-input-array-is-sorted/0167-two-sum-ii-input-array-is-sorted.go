func twoSum(numbers []int, target int) []int {
    var left int = 0
    var right int = len(numbers) - 1
 
    for left < right {
        if numbers[right] + numbers[left] > target{
            right--
        }
        
        if numbers[right] + numbers[left] < target{
            left++
        }
        if numbers[right] + numbers[left] == target{
            break
        }
    }
    
    result := []int{left + 1, right + 1}
    return result
    
}