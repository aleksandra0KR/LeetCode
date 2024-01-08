class Solution {
    public int maxArea(int[] height) {
        int res = 0;
        int left = 0;
        int right = height.length - 1;
        int square;

        while(left < right){
            square = Math.min(height[left], height[right]) * (right - left);

            if (res < square) res = square;

            if(height[left] < height[right]) left++;
            else right--;
        }

        return res;
    }
}