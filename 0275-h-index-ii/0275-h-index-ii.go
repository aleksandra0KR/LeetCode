func hIndex(citations []int) int {
    left := 0
    right := citations[len(citations) - 1]
    result := 0
    for left <= right {
        mid := (right + left) / 2
        counter := 0
        position := 0
        
        for position < len(citations) {
            if citations[position] >= mid {
                 counter++
            }
            position++
        }
        
        if counter >= mid  {
            result = mid
            left = mid + 1
        } else {
            right = mid - 1
        }
        
    }
    return result
}