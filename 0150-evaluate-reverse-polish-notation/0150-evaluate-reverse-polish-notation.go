func evalRPN(tokens []string) int {
    st := make([]int,1)
    result := 0
    tmpNumber := 0
      
    for  _, a := range tokens{
            
        number, err := strconv.Atoi(a)
        if err == nil {
            st = append(st, number)
        } else{
                
            tmpNumber = st[len(st) - 1]
            st = st[0:len(st) - 1]
            result = st[len(st) - 1]
       
            if a == "-"{
                result -= tmpNumber
            }else if a == "+" {
                result += tmpNumber
            }else if a == "/"{
                result /= tmpNumber;
            }else if a == "*"{
                result *= tmpNumber;               
            }
            st = st[0:len(st) - 1]
            st = append(st, result)
                
        }    
    }
    return st[len(st) - 1]
}