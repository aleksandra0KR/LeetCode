func simplifyPath(path string) string {
    st := make([]string,1);
    tempt := ""
    
    for i, _ := range path{
        
        if path[i] != '/' {
            tempt += string(rune(path[i]))
        } else{
               
            if tempt == ".."{
                    
                if len(st) > 1 {
                        
                    for  st[len(st)-1] == "/" && len(st) > 1{
                        st = st[:len(st)-1]
                    }
                    if len(st) >1 {
                     st = st[:len(st)-1]
                    }
                }  
                
            }else if tempt == "."{
                tempt = ""
            }  else if (st[len(st)-1] == "/")  && tempt == ""{
                continue
            } else if (tempt!= "") {
                st = append(st,tempt)
            }
                
            tempt = ""
                
            if st[len(st)-1] != "/" && i != len(path) - 1 {
                st = append(st,"/")
            }
                
         }  
    }
    
    if tempt == ".."{
                    
        if (len(st) > 1) {
                        
            for st[len(st)-1] == "/" && len(st) > 1{
                st = st[:len(st)-1]
            }
            if (len(st) > 1) {
                st = st[:len(st)-1]
            }
                    }                    
    } else if tempt == "."{
        tempt = ""
    } else if (st[len(st)-1] == "/")  && tempt == ""{
        
    }else if tempt!= ""{
        st = append(st,tempt)
    }
                
                
        
    result := "";
    temp := make([]string,0)
      
    for len(st) > 0{
            
        temp = append(temp,st[len(st)-1])
        st = st[:len(st)-1]
     }
    
    for i, j := 0, len(temp)-1; i < j; i, j = i+1, j-1 {
        temp[i], temp[j] = temp[j], temp[i]
    }
        
        
    for i := 0; i < len(temp); i++{
            
        if(i == (len(temp) - 1)) && temp[i] == "/" {
            continue
        }
        result += temp[i]
    }
        
    if result == ""{
        return "/"
    } 
    return result
    
}