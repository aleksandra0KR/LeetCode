class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        else if(nums.size() == 1) return 1;
    
        sort(nums.begin(), nums.end());
        
        int maxConsequence = 0;
        int current = 0;
        
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i+1] - 1) current++;
            else if(nums[i] == nums[i+1]) continue;
            
            else{
                maxConsequence = maxConsequence < current ? current : maxConsequence;
                current = 0;
            }
    
        }
        
                        
        maxConsequence = maxConsequence < current ? current : maxConsequence;

        return ++maxConsequence;
    }
};