class Solution {
    public int removeDuplicates(int[] nums) {
        int position = 0;
        int counter = 0;
        int prev = nums[0];
        for (int a: nums) {
            if (a == prev && counter < 2) {
                counter++;
                nums[position] = a;
                position++;

            } 
            else if (a != prev) {
                counter = 1;
                prev = a;
                nums[position] = a;
                position++;
            }
        }  
        return position;
    }
}