class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        if(nums[l]<=nums[h])return nums[l];
        while(h>l)
        {
            int m=l+(h-l)/2;
            if(nums[m]>=nums[0])l=m+1;
            else
            h=m;
        }
        return nums[l];
    }
};
