class Solution {
    public String reverseWords(String s) {
    
        s = s.trim(); 
        int n = s.length();
        int j = 0;
        List<String> m = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == ' ') {
                if (i > j) { 
                    m.add(s.substring(j, i));
                    m.add(" ");
                }
                j = i + 1;
            }
        }
        if (j < n) {
            m.add(s.substring(j));
        }
        StringBuilder str = new StringBuilder();
        for (int i = m.size() - 1; i >= 0; i--) {
            str.append(m.get(i));
        }
        return str.toString();
    }
}