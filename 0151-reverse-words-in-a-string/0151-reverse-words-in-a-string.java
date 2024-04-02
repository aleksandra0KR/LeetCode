class Solution {
    public String reverseWords(String s) {
    
        String result = "";
        int j;
        
        for(int i = 0; i < s.length(); i++) {
            
            if (s.charAt(i) == ' ') continue;
            
            for(j = i; j < s.length(); j++) {
                if(s.charAt(j) == ' ') break;
            }
            
            if (result == "") {
                result = s.substring(i,j);
            } else{
                 result = s.substring(i,j) + " " + result;
            }
        
            i = j;
        }
        
        return result;
    }
}