func twoSum(numbers []int, target int) []int {
    
    var right int = len(numbers) - 1
 
    for left := 0; left < len(numbers); left++ {
        for numbers[right] + numbers[left] > target{
            right--
        }
        if numbers[right] + numbers[left] == target{
            result := []int{left + 1, right + 1}
            return result
        }
    }
     return []int{}
    
    
}