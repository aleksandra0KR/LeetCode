func hIndex(citations []int) int {
    sort.Slice(citations, func(i, j int) bool {
        return citations[i] > citations[j]
    } )
    
    result := 0
    for i := 0; i < len(citations); i++{
        if i + 1 <= citations[i] {
            result = i + 1
        } else {
            return result
        }
    }
    
    return result
}