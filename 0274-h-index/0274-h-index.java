class Solution {
    public int hIndex(int[] citations) {

        Arrays.sort(citations);

        int result = 0;
        for(int i = 0; i < citations.length; i++){
            if(i + 1 <= citations[citations.length - 1 - i]) {
                result = i + 1;
            }
            else return result;
        }
        
        return result;
    }
}