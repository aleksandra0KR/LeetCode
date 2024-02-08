class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        st.push("/");
        string tempt = "";
        bool newdir = false;
        bool dots = true;
        for(int i = 0; i< path.size();i++){
            if(path[i] != '/') tempt += path[i];
            
            else{
               
                if(tempt == ".."){
                    
                    if (st.size() > 1) {
                        
                        while(st.top() == "/" and st.size()>1) st.pop();
                         if (st.size()>1) st.pop();
                    }                    
                }
                
                else if(tempt == ".")  tempt = "";
                
                else if((st.top() == "/")  and tempt == "") continue;
                
                else if (tempt!= "") st.push(tempt);
                
                tempt = "";
                
                if (st.top() != "/" and i != path.size() - 1) st.push("/");
                
            }    
        }
        
       if(tempt == ".."){
                    
                    if (st.size() > 1) {
                        
                        while(st.top() == "/" and st.size()>1) st.pop();
                         if (st.size()>1) st.pop();
                    }                    
                }
                
                else if(tempt == ".")  tempt = "";
                
                else if((st.top() == "/")  and tempt == "");
                
                else if (tempt!= "") st.push(tempt);
                
                
         

        string result = "";
        vector<string> temp;
      
        while(st.size() > 0){
            
            temp.push_back( st.top());
            st.pop();
        }
        
        reverse(temp.begin(), temp.end());
        
        for(int i = 0; i < temp.size(); i++){
            
            if((i == (temp.size() - 1)) and temp[i] == "/") continue;
            result += temp[i];
        }
        
        if (result == "") return "/";
        return result;
        
        
    }
};