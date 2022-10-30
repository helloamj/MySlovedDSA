class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {    
            int n=floor(log10(nums[i])+1);
             if(!(n & 1))cnt++;
        }
        return cnt;
    }
};
