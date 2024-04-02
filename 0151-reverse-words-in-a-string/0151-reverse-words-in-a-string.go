func reverseWords(s string) string {
    var j int
    result := ""
    
    for i := 0; i < len(s); i++ {
        if s[i] == ' ' {
            continue
        }
        
        j = i
        for j = i; j < len(s); j++ {
            if s[j] == ' '{
                break
            }
        }
        
        if result == ""{
            result = s[i:j]
        } else{
            result = s[i:j] + " " + result
        }
        i = j
    }
    
    return result
}