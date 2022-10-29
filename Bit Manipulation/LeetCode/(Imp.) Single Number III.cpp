class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x=0;
        vector<int> v(2,0);
        //XOR of all Elements
        for(int i=0;i<nums.size();i++)
            x^=nums[i];
        //Last Set Bit Mask -->sn
        long long sn = x&~(x-1);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&sn)v[0]^=nums[i];
            else v[1]^=nums[i];
        }
        return v;
    }
};
