func hIndex(citations []int) int {
    all := make([]int, 10000)
    maxValue := 0
    
    for i:= 0; i < len(citations); i++ {
        for citations[i] - 1 >= 0 {
            citations[i]--
            all[citations[i]]++
        }
    }
    
    for i:= 0; i < len(all); i++ {
        if all[i] >= i + 1 {
            maxValue = i + 1
        }
    }
    
    
    return maxValue
}