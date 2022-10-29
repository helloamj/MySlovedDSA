class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=nums[0],slow=nums[0];
           
        //Move Fast 2 Steps forward then Slow
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
            
        }while(slow!=fast);
        
        //set fast to 0th index and move like slow ( 1 step at a time)
        
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
