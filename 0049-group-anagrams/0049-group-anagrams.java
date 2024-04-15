class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> m = new HashMap<>();
        
        char[] sortedWord;
        String sortedString;
        
        for(String word: strs){
            
            sortedWord  = word.toCharArray();
            Arrays.sort(sortedWord);
            sortedString = new String(sortedWord);
            
            if (! m.containsKey(sortedString)){
               m.put(sortedString, new ArrayList<>());
            }
            
            m.get(sortedString).add(word);
        }
           
        return new ArrayList<>(m.values());
    }
}