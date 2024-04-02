class Solution {
    public String reverseWords(String s) {
        List<String> m = new ArrayList<>();
        StringBuilder word = new StringBuilder();
        
        for(var a : s.toCharArray()) {
            if(a == ' ') {
                if(word.length() != 0) {
                    m.add(word.toString());
                    word.setLength(0);
                }
            } else {
                word.append(a);
            }
        }
        
        if(word.length() != 0) {
            m.add(word.toString()); 
            word.setLength(0);
        }
        
        for(int i = m.size() - 1; i > 0; i--) {
            word.append(m.get(i));
            word.append(" ");
        }
        
        word.append(m.get(0));
        
        return word.toString();
    }
}