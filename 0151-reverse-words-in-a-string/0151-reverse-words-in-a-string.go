func reverseWords(s string) string {
    var m []string
    var word strings.Builder
    for _, a := range s{
        if a == ' ' {
            if len(word.String()) != 0 {
            m = append(m, word.String())
            word.Reset()
            }
        } else {
            word.WriteRune(a)
        }
    }
     if len(word.String()) != 0 {
        m = append(m, word.String())
     }
    word.Reset()
    for i:= len(m) - 1; i > 0; i-- {
        word.WriteString(m[i])
        word.WriteString(" ")
    }
    word.WriteString(m[0])
    
    return word.String()
}