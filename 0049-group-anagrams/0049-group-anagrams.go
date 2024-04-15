func groupAnagrams(strs []string) [][]string {
    m := make(map[string][]string)
    
    for _ , word := range strs {
        chars := []rune(word)
        sort.Slice(chars, func(i, j int) bool {
            return chars[i] < chars[j]
         })
    
        m[string(chars)] = append(m[string(chars)], word)
    }
    
    var result [][]string
    for _, str := range m {
        result = append(result, str)
    }
    
    return result
    
    
    
      
   
    
}