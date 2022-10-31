class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(),nums.end());      // Completely Reverse the Array
        reverse(nums.begin(),nums.begin()+k);  // Reverse from nums[0] to nums[0+k-1]
        reverse(nums.begin()+k,nums.end());    // Reverse from nums[0+k] to nums[n-1]
        
        //or
        
        //rotate(nums.rbegin(), nums.rbegin() + k%nums.size(), nums.rend());
    }
};
