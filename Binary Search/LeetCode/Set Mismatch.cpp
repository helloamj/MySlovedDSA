class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> v = {-1,-1};
        for(int i=0;i<n;i++)
        {
            int num = abs(nums[i]);
            
            if(nums[num-1] < 0)
                v[0] = num;
            else
                nums[num-1] *= (-1);
            
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                v[1]=i+1;
               break;
            }
            
        }
        return v;
    }
};
