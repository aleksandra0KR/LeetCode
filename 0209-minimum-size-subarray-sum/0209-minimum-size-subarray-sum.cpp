class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        
        int left = 0;
        int right = 0;
        int numsLenght = nums.size();
        int resLenght = 1000000;
        while(right < numsLenght){
            
            if(sum < target){
                sum += nums[right];
                right++;
                
            }
            else{
                resLenght = min(resLenght, right - left);
                sum -= nums[left];
                left++;
            }
            
        }
        while(sum >= target){
            resLenght = min(resLenght, right - left);
            sum -= nums[left];
            left ++;
        }
        if(resLenght == 1000000) return 0;
        return resLenght;
    }
};