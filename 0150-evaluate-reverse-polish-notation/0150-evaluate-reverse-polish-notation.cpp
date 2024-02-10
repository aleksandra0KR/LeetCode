class Solution {
public:
    
    int IsNumber(string value){
        
        if(!isdigit(value[0]) and value.size() == 1) return 300;
        
        int result = 0;
        int power = value.size() - 1;
        
        for(int i = 0; i < value.size(); i++){
            if(!isdigit(value[i])) power--;
            
            else{
                result += int(value[i] - '0') * pow(10, power);
                power--;
            }  
        }
        
        if(!isdigit(value[0])) return result * (-1);
        return result;
    }
    
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        int result = 0;
        int tmpNumber;
      
        for(string a: tokens){
            
            int number = IsNumber(a);
            if(number != 300) st.push(number);
            
            else{
                
                tmpNumber = st.top();
                st.pop();
                result = st.top();
       
                if (a == "-"){
                    result -= tmpNumber;
                }
                else if (a == "+" ){
                    result += tmpNumber;
                }
                else if (a == "/"){
                    result /= tmpNumber;
                }
                else if (a == "*"){
                    result *= tmpNumber;               
                }
                st.pop();
                st.push(result);
                
            }    
        }
        return st.top();
    }
};
