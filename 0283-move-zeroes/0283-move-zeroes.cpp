class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;

        while(l<nums.size() && nums[l]!=0)
        {
            l++;
        }
        int r=l+1;

        while(r<nums.size())
        {
            if(nums[r]!=0)
            {
                swap(nums[l],nums[r]);
                l++;
            }
            r++;
        }
    }
};